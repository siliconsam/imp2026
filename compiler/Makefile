.RECIPEPREFIX = >

CC=gcc -no-pie ${M32}
CCFLAGS = -O

BASE_DIR = ${IMP_INSTALL_HOME}
BIN_DIR = ${BASE_DIR}/bin
LIB_DIR = ${BASE_DIR}/lib
INC_DIR = ${BASE_DIR}/include

# Library explicitly located, rather than searched by linker
# So that we can use the newly created library (in ../lib)
# Otherwise use the "official" library in $(BINDIR)
# Also use the possibly "tweaked" local loader script
#LD_SCRIPT = ../pass3/ld.i77.script
#IMP_LIB = ../lib/libimp77.a
#LINK_OPT = ../lib/libimp77.a -lm -T $(LD_SCRIPT)
LD_SCRIPT = $(BIN_DIR)/ld.i77.script
IMP_LIB = $(LIB_DIR)/libimp77.a
LINK_OPT = $(LIB_DIR)/libimp77.a -lm -T $(LD_SCRIPT)
#LD_SCRIPT = $(BIN_DIR)/ld.i77.script
#IMP_LIB = $(LIB_DIR)/libimp77.so
#LINK_OPT = -limp77 -lm -T $(LD_SCRIPT)

OBJS=impdriver.o \
     pass1_i77.o \
     pass2_intel.o \
     icd.utils.o \
     ibj.utils.o \
     incfile.o \
     buffer.o 

#IBJS=takeon.ibj \
#     impdriver.ibj \
#     pass1_i77.ibj \
#     pass2_intel.ibj \
#     ibj.utils.ibj \
#     icd.utils.ibj \
#     buffer.ibj

#IMPS=takeon \
#     impdriver \
#     pass1_i77 \
#     pass2_intel \
#     ibj.utils \
#     icd.utils \
#     buffer

all: takeon impdriver
> @echo "Completed compiler make ALL"

# We need to build takeon, impdriver from their .ibj files (created by the cross build script make.bat)
# Also build pass3 completely from source
bootstrap: takeon.o $(OBJS) $(IMP_LIB) $(LD_SCRIPT)
#bootstrap: pass1 pass2 takeon $(IMPLIB) ld.i77.script
## Just in case convert source files to have Linux line-endings
#> dos2unix i77.grammar
#> dos2unix *.imp
#> dos2unix *.ibj
# Next create the object files from the .ibj files

# Now build the programs
> @$(CC) -o takeon takeon.o   $(LINK_OPT)
> @$(CC) -o impdriver $(OBJS) $(LINK_OPT)

# Lastly install the two programs
> @install -t ${BIN_DIR} takeon
> @install -t ${BIN_DIR} impdriver
> @echo "Completed compiler make BOOTSTRAP"

rebuild: i77.tables.inc $(OBJS)
# Now build the programs
> @$(CC) -o impdriver $(OBJS) $(LINK_OPT)
> @echo "Completed compiler make REBUILD"
>

# We need to build takeon, impdriver
install: takeon impdriver 
# Firstly, install the parser generator
> @install -t $(BIN_DIR) takeon
# Next, install the executables for pass1,pass2
> @install -t $(BIN_DIR) impdriver
> @echo "Completed compiler make INSTALL"
>

# do a minimal tidy up of programs and temporary files
clean: #
> @rm -f takeon
> @rm -f impdriver
> @rm -f pass1_i77
> @rm -f pass2_intel
> @rm -f i77.tables.inc
> @rm -f *.o
> @rm -f *.debug
> @rm -f *.cod
> @rm -f *.icd
> @rm -f *.lst
> @echo "Completed compiler make CLEAN"
>

# really scrub away all programs and temporary files
superclean: clean
> @rm -f *.ibj
> @echo "Completed compiler make SUPERCLEAN"
>

takeon: takeon.o
> @$(CC) -o takeon takeon.o $(LINK_OPT)
> @echo "Completed compiler make TAKEON"

i77.tables.inc: i77.grammar takeon
> #@$(BIN_DIR)/takeon i77.grammar=i77.tables.inc,i77.par.debug,i77.lex.debug
> @./takeon i77.grammar=i77.tables.inc,i77.par.debug,i77.lex.debug
> @echo "Completed compiler make I77.TABLES.INC"

impdriver: i77.tables.inc $(OBJS)
> @${CC} -o impdriver $(OBJS) $(LINK_OPT)
> @echo "Completed compiler make IMPDRIVER"

%.o: %.c
> @$(CC) -c $(CCFLAGS) $<

%.o: %.ibj
> @echo "Using pass3elf to create `basename $< .ibj`.o from $<"
> @${IMP_INSTALL_HOME}/bin/pass3elf `basename $< .ibj`.ibj `basename $< .ibj`.o

%.ibj: %.imp
> @echo "Using imp77 script to create `basename $< .imp`.o from $<"
> @${IMP_INSTALL_HOME}/bin/imp77 -c -Fc -Fs -Fi $<

%.o: %.imp
> @echo "Using imp77 script to create `basename $< .imp`.o from $<"
> @${IMP_INSTALL_HOME}/bin/imp77 -c -Fc -Fs -Fi $<
