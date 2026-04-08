#!/bin/bash
# Simple IMP compiler shell wrapper

echo "$0"
echo "${PWD}"

IMP_SOURCE_HOME=${PWD}
IMP_INSTALL_HOME=${IMP_SOURCE_HOME}/release

export IMP_SOURCE_HOME=${PWD}
export IMP_INSTALL_HOME=${IMP_SOURCE_HOME}/release

echo "IMP Source in ${IMP_SOURCE_HOME}"
echo "Installing to ${IMP_INSTALL_HOME}"

if [ ! -e ${IMP_INSTALL_HOME} ]; then
    mkdir ${IMP_INSTALL_HOME}
fi

if [ ! -e ${IMP_INSTALL_HOME}/bin ]; then
    mkdir ${IMP_INSTALL_HOME}/bin
fi
if [ ! -e ${IMP_INSTALL_HOME}/include ]; then
    mkdir ${IMP_INSTALL_HOME}/include
fi
if [ ! -e ${IMP_INSTALL_HOME}/lib ]; then
    mkdir ${IMP_INSTALL_HOME}/lib
fi

cd ${IMP_SOURCE_HOME}/pass3
# Now to select an appropriate loader script for the gcc version
gcc -dumpversion > gcc.version.lis
READONLY=$(cat gcc.version.lis)
if [ ${READONLY} -lt 11 ]; then
    cp ld.i77.gcc10.script ld.i77.script
else
    cp ld.i77.gcc11.script ld.i77.script
fi
unset READONLY
rm gcc.version.lis
# Now build the pass3 programs and the loader script
make bootstrap


cd ${IMP_SOURCE_HOME}/lib
make loadlinux
touch *.ibj
make bootstrap

cd ${IMP_SOURCE_HOME}/compiler
make bootstrap

cd ${IMP_SOURCE_HOME}/pass3
make clean

cd ${IMP_SOURCE_HOME}/lib
make clean

cd ${IMP_SOURCE_HOME}/compiler
make clean

cd ${IMP_SOURCE_HOME}
