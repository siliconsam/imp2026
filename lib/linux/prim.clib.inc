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
                        %alias "exit"             %c
                        (%integer status)
    {------------------------------------------------------------------------}
    {------------------------------------------------------------------------}
    { External C routines used for file acess                                }
    {------------------------------------------------------------------------}
    %external %integer %fn %spec prim get error       %c
                           %alias "geterrno"
    %external %integer %fn %spec prim geterrhandle    %c
                           %alias "getstderr"
    %external %integer %fn %spec prim getinhandle     %c
                           %alias "getstdin"
    %external %integer %fn %spec prim getouthandle    %c
                           %alias "getstdout"
    %external %integer %fn %spec prim openfile        %c
                           %alias "fopen"            %c
                           (%integer mode address, %integer file name address)
    %external %integer %fn %spec prim tell            %c
                           %alias "ftell"            %c
                           (%integer handle)
    %external %routine     %spec prim file rewind     %c
                           %alias "rewind"           %c
                           (%integer handle)
    %external %routine     %spec prim file seek       %c
                           %alias "fseek"            %c
                           (%integer handle, displacement, pos)
    %external %routine     %spec prim close           %c
                           %alias "fclose"           %c
                           (%integer handle)
    %external %integer %fn %spec prim readbytes       %c
                           %alias "fread"            %c
                           (%integer handle, count, itemsz, %byte %name buffer)
    %external %integer %fn %spec prim writebytes      %c
                           %alias "fwrite"           %c
                           (%integer handle, count, itemsz, %byte %name buffer)
    %external %integer %fn %spec prim eof             %c
                           %alias "feof"             %c
                           (%integer handle)
    %external %integer %fn %spec prim get char        %c
                           %alias "fgetc"            %c
                           (%integer handle)
    %external %routine     %spec prim put char        %c
                           %alias "fputc"            %c
                           (%integer handle,ch)
    %external %routine     %spec prim flush           %c
                           %alias "fflush"           %c
                           (%integer handle)
    {------------------------------------------------------------------------}
    {------------------------------------------------------------------------}
    { External C routines used for heap data creation/removal                }
    {------------------------------------------------------------------------}
    %external %routine           %spec impfree        %c
                                 %alias "free"       %c
                                 ( %integer templateaddr )
    %external %record( * ) %map  %spec impmalloc      %c
                                 %alias "malloc"     %c
                                 ( %integer s )
    {------------------------------------------------------------------------}
    {------------------------------------------------------------------------}
    { C routines implementing simple mathematics library functions           }
    { These routines can also be implemented using embedded x86 instructions }
    {------------------------------------------------------------------------}
    %external %long %real %fn    %spec C Lib Cos      %c
                                 %alias "cos"        %c
                                 ( %longreal r)
    %external %long %real %fn    %spec C Lib Sine     %c
                                 %alias "sin"        %c
                                 ( %longreal r)
    %external %long %real %fn    %spec C Lib Log10    %c
                                 %alias "log10"      %c
                                 ( %longreal x)
    %external %long %real %fn    %spec C Lib Log      %c
                                 %alias "log"        %c
                                 ( %longreal x)

    {------------------------------------------------------------------------}
    {------------------------------------------------------------------------}

%list
%endoffile
