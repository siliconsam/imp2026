.RECIPEPREFIX = >
CC = gcc ${M32}
CCFLAGS = -O

# LOOK! Change these three if they don't match your local policies
BASEDIR = ${IMP_INSTALL_HOME}
BINDIR = ${IMP_INSTALL_HOME}/bin
LIBDIR = ${IMP_INSTALL_HOME}/lib
INCDIR = ${IMP_INSTALL_HOME}/include

IOPRIMS=prim-library.o

IMPCORE=impcore-arrayutils.o \
     impcore-base.o \
     impcore-signal.o

IMPLIB=implib-arg.o \
     implib-debug.o \
     implib-env.o \
     implib-read.o \
     implib-strings.o 

IMPRTL=imprtl-check.o \
     imprtl-event.o \
     imprtl-io.o \
     imprtl-limit.o \
     imprtl-line.o \
     imprtl-mathutils.o \
     imprtl-trap.o \
     imprtl-main.o

OBJS=prim-rtl-file.o \
     $(IOPRIMS) \
     $(IMPCORE) \
     $(IMPLIB) \
     $(IMPRTL) 

LIST=prim.clib.inc \
     prim-library.ibj \
     imprtl-main.imp \
     imprtl-main.ibj

all: libimp77.a
> @echo "Completed lib make ALL"

#bootstrap: libimp77.so libimp77.a stdperm.imp
bootstrap: libimp77.a stdperm.imp
# install the libraries and core include file
> @install -t $(LIBDIR) libimp77.a
> @#install -t $(LIBDIR) libimp77.so
> @install -t $(INCDIR) stdperm.imp
> @echo "Completed lib make BOOTSTRAP"

#rebuild: libimp77.so libimp77.a stdperm.imp
rebuild: libimp77.a stdperm.imp
# First, install the libraries and core include file
# finally, ensure all text files have Unix line-endings
> @echo "Completed lib make REBUILD"

#install: libimp77.so libimp77.a stdperm.imp
install: libimp77.a stdperm.imp
# Install the libraries and core include file
> @install -t $(LIBDIR) libimp77.a
> @install -t $(LIBDIR) imprtl-main.o
> @#install -t $(LIBDIR) libimp77.so
> @install -t $(INCDIR) stdperm.imp
> @echo "Completed lib make INSTALL"

clean: #
> @rm -f *.a
> @rm -f *.so
> @rm -f *.o
> @rm -f *.cod
> @rm -f *.icd
> @rm -f *.lst
> @echo "Completed lib make CLEAN"

superclean: clean
> @rm -f *.ibj
> @echo "Completed lib make SUPERCLEAN"

loadlinux: #
> @cp -f ./linux/* ./
> @echo "Completed lib make LOADLINUX"

loadwindows: #
> @cp -f ./windows/* ./
> @echo "Completed lib make LOADWINDOWS"

storelinux: $(LIST)
> @cp -f $(LIST) ./linux
> @echo "Completed lib make STORELINUX"

storewindows: $(LIST)
> @cp -f $(LIST) ./windows
> @echo "Completed lib make STOREWINDOWS"

libimp77.a: $(OBJS)
> @ar -c -r libimp77.a $(OBJS)
> @ranlib libimp77.a
> @echo "Completed lib make LIBIMP77.A"

libimp77.so: $(OBJS)
> @${CC} -shared -fPIC -Wl,-soname,libimp77.so -o libimp77.so $(OBJS)
> @echo "Completed lib make LIBIMP77.SO"

%.o: %.c
> @$(CC) -c $(CCFLAGS) $<

%.o: %.ibj
> @echo "Using pass3elf to create `basename $< .ibj`.o from $<"
> @${BINDIR}/pass3elf `basename $< .ibj`.ibj `basename $< .ibj`.o

%.ibj: %.imp
> @echo "Using imp77 script to create `basename $< .imp`.o from $<"
> @${IMP_INSTALL_HOME}/bin/imp77 -c -Fc -Fs -Fi $<

%.o: %.imp
> @echo "Using imp77 script to create `basename $< .imp`.o from $<"
> @${IMP_INSTALL_HOME}/bin/imp77 -c -Fc -Fs -Fi $<
