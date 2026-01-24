%endoflist

    ! Curious naming strategy because we don't want to clobber
    ! the built-in functions and maps like "integer" or "int"
    ! Types extracted from general names
    %constinteger  general type   = 0
    %constinteger  integer type   = 1
    %constinteger  real type      = 2
    %constinteger  string type    = 3
    %constinteger  record type    = 4
    %constinteger  byte type      = 5
    %constinteger  short type     = 6
    %constinteger  long type      = 7
    %constinteger  long real type = 8
    ! JDM JDM additional datatypes added for use by typeof/sizeof functions
    ! They correspond to some of the external forms
    %constinteger  array type     = 9
    %constinteger  label type     = 10

    ! Size of the various types (in bytes)
    %constinteger address size       = 4
    %constinteger integer size       = 4
    %constinteger real size          = 4
    ! stringsize is undefined (it could be in range 1..255)
    ! recordsize is undefined (it depends on the record format)
    %constinteger byte size          = 1
    %constinteger short size         = 2
    %constinteger long size          = 4
    %constinteger long real size     = 8
    %constinteger extended real size = 10
    ! arraysize undefined (it depends on dimensions+entry size)
    ! labelsize undefined (it is not a stored value)

    ! Limits
    ! MaxInt,MaxShort is all bits set bar the most significant bit
    ! for the size of %integer, %short
    %constinteger        MaxInt = ((-1)>>1)
    %constinteger      MaxShort = ((-1)>>17)
    ! MaxByte is all bits set for the low 8-bits
    %constinteger       MaxByte = ((-1)>>24)
    %constlongreal     MaxFloat = 3.3@38
    %constinteger  MaxStringLen = MaxByte

    ! for a %name the order of pushing it's data onto the stack
    ! when passing as a parameter is
    ! 1) the DVP (value or pointer)
    ! 2) the variable address
    ! However, when reading the %name parameter inside the
    ! routine/function the actual data is in reverse order
    ! So, we read the data as
    ! 1) address
    ! 2) DVP
    %recordformat namefm(%integer address,dvp)

%list
%endoffile
