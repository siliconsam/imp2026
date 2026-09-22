#!/bin/bash
# Simple IMP compiler shell wrapper

IMP_BASE=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

echo "running ${IMP_BASE}/setenv.sh from ${PWD}"

if [ -z ${IMP_SOURCE_HOME} ]; then
    export IMP_SOURCE_HOME="${IMP_BASE}"
    export IMP_INCLUDE_HOME="${IMP_BASE}/include"
    export IMP_FILESEP="/"
fi

if [ -z ${IMP_INSTALL_HOME} ]; then
    if [ ! -e ${IMP_BASE}/release ]; then
        mkdir ${IMP_BASE}/release
    fi
    if [ ! -e ${IMP_BASE}/release/bin ]; then
        mkdir ${IMP_BASE}/release/bin
    fi
    if [ ! -e ${IMP_BASE}/release/include ]; then
        mkdir ${IMP_BASE}/release/include
    fi
    if [ ! -e ${IMP_BASE}/release/lib ]; then
        mkdir ${IMP_BASE}/release/lib
    fi
    export IMP_INSTALL_HOME=${IMP_BASE}/release
    export PATH=${IMP_INSTALL_HOME}/bin:${PATH}
fi

if [ -z ${IMP_TOOLS_HOME} ]; then
    export IMP_TOOLS_HOME="${IMP_INSTALL_HOME}"
fi

export IMP_FILESEP=/

bash
