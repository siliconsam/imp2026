%endoflist
    {------------------------------------------------------------------------}
    { External Library routines implemented in C                             }
    { These routines use an alias name to refer to the actual C routine      }
    { The alias name may need to be changed for different operating systems  }
    {------------------------------------------------------------------------}

    {------------------------------------------------------------------------}
    { External C routines used to manipulate processes                       }
    {------------------------------------------------------------------------}
    %external %routine  %spec prim exit            %c
                        %alias "_exit"             %c
                        (%integer status)
    {------------------------------------------------------------------------}
    {------------------------------------------------------------------------}
    { External C routines used for file acess                                }
    {------------------------------------------------------------------------}
    %external %integer %fn %spec prim get error       %c
                           %alias "_geterrno"
    %external %integer %fn %spec prim geterrhandle    %c
                           %alias "_getstderr"
    %external %integer %fn %spec prim getinhandle     %c
                           %alias "_getstdin"
    %external %integer %fn %spec prim getouthandle    %c
                           %alias "_getstdout"
    %external %integer %fn %spec prim openfile        %c
                           %alias "_fopen"            %c
                           (%integer mode address, %integer file name address)
    %external %integer %fn %spec prim tell            %c
                           %alias "_ftell"            %c
                           (%integer handle)
    %external %routine     %spec prim file rewind     %c
                           %alias "_rewind"           %c
                           (%integer handle)
    %external %routine     %spec prim file seek       %c
                           %alias "_fseek"            %c
                           (%integer handle, displacement, pos)
    %external %routine     %spec prim close           %c
                           %alias "_fclose"           %c
                           (%integer handle)
    %external %integer %fn %spec prim readbytes       %c
                           %alias "_fread"            %c
                           (%integer handle, count, itemsz, %byte %name buffer)
    %external %integer %fn %spec prim writebytes      %c
                           %alias "_fwrite"           %c
                           (%integer handle, count, itemsz, %byte %name buffer)
    %external %integer %fn %spec prim eof             %c
                           %alias "_feof"             %c
                           (%integer handle)
    %external %integer %fn %spec prim get char        %c
                           %alias "_fgetc"            %c
                           (%integer handle)
    %external %routine     %spec prim put char        %c
                           %alias "_fputc"            %c
                           (%integer handle,ch)
    %external %routine     %spec prim flush           %c
                           %alias "_fflush"           %c
                           (%integer handle)
    {------------------------------------------------------------------------}
    {------------------------------------------------------------------------}
    { External C routines used for heap data creation/removal                }
    {------------------------------------------------------------------------}
    %external %routine           %spec impfree        %c
                                 %alias "_free"       %c
                                 ( %integer templateaddr )
    %external %record( * ) %map  %spec impmalloc      %c
                                 %alias "_malloc"     %c
                                 ( %integer s )
    {------------------------------------------------------------------------}
    {------------------------------------------------------------------------}
    { C routines implementing simple mathematics library functions           }
    { These routines can also be implemented using embedded x86 instructions }
    {------------------------------------------------------------------------}
    %external %long %real %fn    %spec C Lib Cos      %c
                                 %alias "_cos"        %c
                                 ( %longreal r)
    %external %long %real %fn    %spec C Lib Sine     %c
                                 %alias "_sin"        %c
                                 ( %longreal r)
    %external %long %real %fn    %spec C Lib Log10    %c
                                 %alias "_log10"      %c
                                 ( %longreal x)
    %external %long %real %fn    %spec C Lib Log      %c
                                 %alias "_log"        %c
                                 ( %longreal x)

    {------------------------------------------------------------------------}
    {------------------------------------------------------------------------}

%list
%endoffile
