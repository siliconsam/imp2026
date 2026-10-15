%endoflist

    %external %integer     %function %spec get maxtag
    %external              %routine  %spec set symbol data( %integer tag, %string(255) name, %integer tf, size, scope)
    %external %string(255) %function %spec get symbol name( %integer tag )
    %external %integer     %function %spec get symbol tf( %integer tag )
    %external %integer     %function %spec get symbol size( %integer tag )
    %external %integer     %function %spec get symbol scope( %integer tag )

    %external %string(15)  %function %spec form own String( %integer flags )
    %external %string(63)  %function %spec form flags string( %integer flags )
    %external %string(255) %function %spec form type def( %integer type,size )
    %external %integer     %function %spec form entry type( %integer type, size )
    %external %string(15)  %function %spec form typeof String( %integer type )
    %external %string(15)  %function %spec form type name( %integer type)
    %external %string(15)  %function %spec form external form name( %integer form )
    %external %string(15)  %function %spec form internal form name( %integer form )
    %external %string(15)  %function %spec form ICode Name( %integer code )
    %external %integer     %function %spec ReadTag
    %external %integer     %function %spec ReadTagComma
    %external %integer     %function %spec ReadInteger
    %external %integer     %function %spec ReadByte
    %external %longreal    %function %spec ReadReal
    %external %string(255) %function %spec ReadString
    %external %string(255) %function %spec Get Ascii( %integer terminator)
    %external %integer     %function %spec ReadICode
    %external %integer     %function %spec lookahead icode
    %external              %routine  %spec next iCode

%list
%endoffile
