%endoflist

                                          {NUL} {   0 ASCII unused }
                                          {SOH} {   1 ASCII unused }
                                          {STX} {   2 ASCII unused }
                                          {ETX} {   3 ASCII unused }
                                          {EOT} {   4 ASCII unused }
                                          {ENQ} {   5 ASCII unused }
                                          {ACK} {   6 ASCII unused }
                                          {BEL} {   7 ASCII unused }
                                          {BS } {   8 ASCII unused }
                                          {HT } {   9 ASCII unused }
    %constantbyteinteger iCodeEOF       = 10    {  10 }
                                          {VT } {  11 ASCII unused }
                                          {FF } {  12 ASCII unused }
                                          {CR } {  13 ASCII unused }
                                          {SO } {  14 ASCII unused }
                                          {SI } {  15 ASCII unused }
                                          {DLE} {  16 ASCII unused }
                                          {DC1} {  17 ASCII unused }
                                          {DC2} {  18 ASCII unused }
                                          {DC3} {  19 ASCII unused }
                                          {DC4} {  20 ASCII unused }
                                          {NAK} {  21 ASCII unused }
                                          {SYN} {  22 ASCII unused }
                                          {ETB} {  23 ASCII unused }
                                          {CAN} {  24 ASCII unused }
                                          {EM } {  25 ASCII unused }
                                          {SUB} {  25 ASCII unused }
                                          {ESC} {  27 ASCII unused }
                                          {FS } {  28 ASCII unused }
                                          {GS } {  29 ASCII unused }
                                          {ES } {  30 ASCII unused }
                                          {US } {  31 ASCII unused }
                                          { }   {  32 ASCII unused }
    %constantbyteinteger iCodeOR        = '!'   {  33 }
    %constantbyteinteger iCodeCOMPARED  = '"'   {  34 }
    %constantbyteinteger iCodeJNE       = '#'   {  35 }
    %constantbyteinteger iCodeDEF       = '$'   {  36 }
    %constantbyteinteger iCodeXOR       = '%'   {  37 }
    %constantbyteinteger iCodeAND       = '&'   {  38 }
    %constantbyteinteger iCodePUSHS     = ''''  {  39 }
    %constantbyteinteger iCodeJLE       = '('   {  40 }
    %constantbyteinteger iCodeJGE       = ')'   {  41 }
    %constantbyteinteger iCodeMUL       = '*'   {  42 }
    %constantbyteinteger iCodeADD       = '+'   {  43 }
                                          {,}   {  44 ASCII unused }
    %constantbyteinteger iCodeSUB       = '-'   {  45 }
    %constantbyteinteger iCodeCONCAT    = '.'   {  46 }
    %constantbyteinteger iCodeQUOT      = '/'   {  47 }
                                          {0}   {  48 ASCII unused }
                                          {1}   {  49 ASCII unused }
                                          {2}   {  50 ASCII unused }
                                          {3}   {  51 ASCII unused }
                                          {4}   {  52 ASCII unused }
                                          {5}   {  53 ASCII unused }
                                          {6}   {  54 ASCII unused }
                                          {7}   {  55 ASCII unused }
                                          {8}   {  56 ASCII unused }
                                          {9}   {  57 ASCII unused }
    %constantbyteinteger iCodeLOCATE    = ':'   {  58 }
    %constantbyteinteger iCodeEND       = ';'   {  59 }
    %constantbyteinteger iCodeJL        = '<'   {  60 }
    %constantbyteinteger iCodeJE        = '='   {  61 }
    %constantbyteinteger iCodeJG        = '>'   {  62 }
    %constantbyteinteger iCodeCOMPARE   = '?'   {  63 }
    %constantbyteinteger iCodePUSH      = '@'   {  64 }
    %constantbyteinteger iCodeINIT      = 'A'   {  65 }
    %constantbyteinteger iCodeREPEAT    = 'B'   {  66 }
    %constantbyteinteger iCodeCOMPAREA  = 'C'   {  67 }
    %constantbyteinteger iCodePUSHR     = 'D'   {  68 }
    %constantbyteinteger iCodeCALL      = 'E'   {  69 }
    %constantbyteinteger iCodeGOTO      = 'F'   {  70 }
    %constantbyteinteger iCodeALIAS     = 'G'   {  71 }
    %constantbyteinteger iCodeBEGIN     = 'H'   {  72 }
                                          {I}   {  73 ASCII unused }
    %constantbyteinteger iCodeJUMP      = 'J'   {  74 }
    %constantbyteinteger iCodeFALSE     = 'K'   {  75 }
    %constantbyteinteger iCodeLABEL     = 'L'   {  76 }
    %constantbyteinteger iCodeMAP       = 'M'   {  77 }
    %constantbyteinteger iCodePUSHI     = 'N'   {  78 }
    %constantbyteinteger iCodeLINE      = 'O'   {  79 }
    %constantbyteinteger iCodePLANT     = 'P'   {  80 }
    %constantbyteinteger iCodeDIVIDE    = 'Q'   {  81 }
    %constantbyteinteger iCodeRETURN    = 'R'   {  82 }
    %constantbyteinteger iCodeASSVAL    = 'S'   {  83 }
    %constantbyteinteger iCodeTRUE      = 'T'   {  84 }
    %constantbyteinteger iCodeNEGATE    = 'U'   {  85 }
    %constantbyteinteger iCodeRESULT    = 'V'   {  86 }
    %constantbyteinteger iCodeSJUMP     = 'W'   {  87 }
    %constantbyteinteger iCodeIEXP      = 'X'   {  88 }
                                          {Y}   {  89 ASCII unused }
    %constantbyteinteger iCodeASSREF    = 'Z'   {  90 }
    %constantbyteinteger iCodeLSH       = '['   {  91 }
    %constantbyteinteger iCodeNOT       = '\'   {  92 }
    %constantbyteinteger iCodeRSH       = ']'   {  93 }
    %constantbyteinteger iCodeSETFORMAT = '^'   {  94 }
    %constantbyteinteger iCodeSLABEL    = '_'   {  95 }
                                          {`}   {  96 ASCII unused }
    %constantbyteinteger iCodeACCESS    = 'a'   {  97 }
    %constantbyteinteger iCodeBOUNDS    = 'b'   {  98 }
    %constantbyteinteger iCodeALTNEXT   = 'c'   {  99 }
    %constantbyteinteger iCodeDIM       = 'd'   { 100 }
    %constantbyteinteger iCodeEVENT     = 'e'   { 101 }
    %constantbyteinteger iCodeFOR       = 'f'   { 102 }
    %constantbyteinteger iCodeALTSTART  = 'g'   { 103 }
    %constantbyteinteger iCodeALTEND    = 'h'   { 104 }
    %constantbyteinteger iCodeINDEX     = 'i'   { 105 }
    %constantbyteinteger iCodeJAM       = 'j'   { 106 }
    %constantbyteinteger iCodeJZ        = 'k'   { 107 }
    %constantbyteinteger iCodeLANG      = 'l'   { 108 }
    %constantbyteinteger iCodeMONITOR   = 'm'   { 109 }
    %constantbyteinteger iCodeSELECT    = 'n'   { 110 }
    %constantbyteinteger iCodeON        = 'o'   { 111 }
    %constantbyteinteger iCodeASSPAR    = 'p'   { 112 }
    %constantbyteinteger iCodeSUBA      = 'q'   { 113 }
    %constantbyteinteger iCodeRESOLVE   = 'r'   { 114 }
    %constantbyteinteger iCodeSTOP      = 's'   { 115 }
    %constantbyteinteger iCodeJNZ       = 't'   { 116 }
    %constantbyteinteger iCodeADDA      = 'u'   { 117 }
    %constantbyteinteger iCodeMOD       = 'v'   { 118 }
    %constantbyteinteger iCodeMCODE     = 'w'   { 119 }
    %constantbyteinteger iCodeREXP      = 'x'   { 120 }
    %constantbyteinteger iCodeDIAG      = 'y'   { 121 }
    %constantbyteinteger iCodeCONTROL   = 'z'   { 122 }
    %constantbyteinteger iCodeSTART     = '{'   { 123 }
                                          {|}   { 124 ASCII unused }
    %constantbyteinteger iCodeFINISH    = '}'   { 125 }
    %constantbyteinteger iCodeALT       = '~'   { 126 }
                                          {DEL} { 127 ASCII unused }

%list
%endoffile
