@setlocal
@echo off
@set COM_HOME=%~dp0
@set SOURCE_DIR=%COM_HOME:~0,-1%
@rem just removed the \ (last character) from the path

@rem rem always use the bootstrap/rebuild library
@rem set LIB_HOME=%IMP_SOURCE_HOME%\lib

@rem use the install library
@set LIB_HOME=%IMP_INSTALL_HOME%\lib

@set PERM_HOME=%IMP_INSTALL_HOME%\include
@set BIN_DIR=%IMP_INSTALL_HOME%\bin
@set COMPILER_LIB=compiler.lib

@pushd %SOURCE_DIR%

:parseargs
@if "%1"==""             @goto help
@if "%1"=="help"         @goto help
@if "%1"=="/h"           @goto help
@if "%1"=="-h"           @goto help
@if "%1"=="bootstrap"    @goto bootstrap
@if "%1"=="rebuild"      @goto rebuild
@if "%1"=="install"      @goto install
@if "%1"=="clean"        @goto clean
@if "%1"=="superclean"   @goto superclean
@if "%1"=="pass1"        @goto pass1
@if "%1"=="pass2"        @goto pass2
@goto help

:bootstrap
@echo.
@echo "COMPILER BOOTSTRAP requested"
@echo.
:do_bootstrap
@call :do_makecompiler ibj
@goto the_end

:rebuild
@echo.
@echo "COMPILER REBUILD requested"
@echo.
:do_rebuild
@call :do_makecompiler imp
@goto the_end

:install
@echo.
@echo "COMPILER INSTALL requested"
@echo.
:do_install
@copy/y takeon.exe     %IMP_INSTALL_HOME%\bin\*
@copy/y impdriver.exe  %IMP_INSTALL_HOME%\bin\*
@goto the_end

:clean
@echo.
@echo "COMPILER CLEAN requested"
@echo.
:do_clean
@if exist *.cod   del *.cod
@if exist *.debug del *.debug
@if exist *.exe   del *.exe
@if exist *.icd   del *.icd
@if exist *.lib   del *.lib
@if exist *.lst   del *.lst
@if exist *.map   del *.map
@if exist *.obj   del *.obj
@goto the_end

:superclean
@echo.
@echo "COMPILER SUPERCLEAN requested"
@echo.
:do_superclean
@if exist *.ibj          del *.ibj
@if exist i77.tables.inc @del i77.tables.inc
@goto do_clean

:pass1
@call :do_pass1 imp
@goto the_end

:pass2
@call :do_pass2 imp
@goto the_end

:do_makecompiler
@set start=%1

@rem compile the utility code
@for %%a in (takeon,ibj.utils,icd.utils,buffer,incfile,impdriver) do (
    @call :do_compile "%%a" %start%
)
@call :do_link takeon

@rem check if we need to recreate the language table data
@if "%start%"=="imp" @if not exist i77.tables.inc (
    @takeon.exe i77.grammar,i77.grammar=i77.tables.inc,i77.par.debug,i77.lex.debug
)

@rem finally compile and link the language syntax recogniser (pass1)
@for %%a in (pass1_i77,pass2_intel) do (
    @call :do_compile "%%a" %start%
)

@call :do_link impdriver pass1_i77 pass2_intel buffer incfile icd.utils ibj.utils
@exit/b

:do_pass1
@set start=%1

@rem compile the utility code
@for %%a in (takeon,ibj.utils,icd.utils,buffer,incfile,pass1driver) do (
    @call :do_compile "%%a" %start%
)
@call :do_link takeon

@rem check if we need to recreate the language table data
@if "%start%"=="imp" @if not exist i77.tables.inc (
    @takeon.exe i77.grammar,i77.grammar=i77.tables.inc,i77.par.debug,i77.lex.debug
)

@rem finally compile and link the language syntax recogniser (pass1)
@for %%a in (pass1_i77,pass2_intel) do (
    @call :do_compile "%%a" %start%
)

@call :do_link pass1driver pass1_i77 pass2_intel buffer incfile icd.utils ibj.utils
@exit/b

:do_pass2
@set start=%1

@rem compile the utility code
@for %%a in (takeon,ibj.utils,icd.utils,buffer,incfile,pass2driver) do (
    @call :do_compile "%%a" %start%
)
@call :do_link takeon

@rem check if we need to recreate the language table data
@if "%start%"=="imp" @if not exist i77.tables.inc (
    @takeon.exe i77.grammar,i77.grammar=i77.tables.inc,i77.par.debug,i77.lex.debug
)

@rem finally compile and link the language syntax recogniser (pass1)
@for %%a in (pass1_i77,pass2_intel) do (
    @call :do_compile "%%a" %start%
)

@call :do_link pass2driver pass1_i77 pass2_intel buffer incfile icd.utils ibj.utils
@exit/b

:do_compile
@set module=%1
@set source=%2
@rem Create the .obj file from the .ibj/.imp file
@if "%source%"=="imp" (
    @%BIN_DIR%\impdriver.exe %PERM_HOME%\stdperm %module%
)
@%BIN_DIR%\pass3coff.exe %module%.ibj %module%.obj
@exit/b

:do_link
@rem Ensure we have a clean library
@if exist %COMPILER_LIB% del %COMPILER_LIB%

@set file1=%1
@set file2=%2
@set file3=%3
@set file4=%4
@set file5=%5
@set file6=%6
@set file7=%7
@if not "%file1%"=="" @lib /nologo /out:%COMPILER_LIB% %file1%.obj
@if not "%file2%"=="" @lib /nologo /out:%COMPILER_LIB% %COMPILER_LIB% %file2%.obj
@if not "%file3%"=="" @lib /nologo /out:%COMPILER_LIB% %COMPILER_LIB% %file3%.obj
@if not "%file4%"=="" @lib /nologo /out:%COMPILER_LIB% %COMPILER_LIB% %file4%.obj
@if not "%file5%"=="" @lib /nologo /out:%COMPILER_LIB% %COMPILER_LIB% %file5%.obj
@if not "%file6%"=="" @lib /nologo /out:%COMPILER_LIB% %COMPILER_LIB% %file6%.obj
@if not "%file7%"=="" @lib /nologo /out:%COMPILER_LIB% %COMPILER_LIB% %file7%.obj

@rem This link command line adds the C heap library code
@rem To exclude the heap code
@rem - 1) uncomment   the line: @rem set HEAP_REQUEST=
@rem - 2) comment out the line: @set HEAP_REQUEST=/heap:0x800000,0x800000

@rem set HEAP_REQUEST=
@set HEAP_REQUEST=/heap:0x800000,0x800000
@link /nologo /SUBSYSTEM:CONSOLE /stack:0x800000,0x800000 %HEAP_REQUEST% ^
/MAPINFO:EXPORTS /MAP:%1.map /OUT:%1.exe ^
/DEFAULTLIB:%LIB_HOME%\libi77.lib %LIB_HOME%\imprtl-main.obj ^
%COMPILER_LIB% ^
%LIB_HOME%\libi77.lib

@exit/b

:help
:do_help
@echo.
@echo  Legal parameters to the MAKE_COMPILER script are:
@echo.
@echo     bootstrap:    - each ibj file is converted to an obj file by pass3coff.exe
@echo                   - the takeon, pass1, pass2 executables are created from the .obj files
@echo                   - and linked using the library file libi77.lib in the .\lib folder
@echo.
@echo     rebuild:      - similar to bootstrap except the start point is a .imp file
@echo.
@echo     install:      - the takeon, pass1, pass3 executables are released to the %IMP_INSTALL_HOME%\bin folder
@echo.
@echo     clean:        - all compiler generated files (except the .ibj files) are deleted
@echo.
@echo     superclean:   - same as 'clean' except the .ibj files are also deleted
@echo.
@echo.
@goto the_end

:the_end
@popd
@endlocal
@exit/b
