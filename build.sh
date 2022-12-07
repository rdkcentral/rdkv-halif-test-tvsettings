#!/usr/bin/env bash

# Clone the Unit Test Requirements
TEST_REPO="git://github.com/comcast-sky/rdk-components-ut-core.git"

SCRIPTDIR="$(dirname "$0")"

UT_CORE_PATH=${SCRIPTDIR}/ut-core

# Set default UT_PROJECT_VERSION to master
if [ -z "${UT_PROJECT_VERSION}" ]; then
    UT_PROJECT_VERSION=master
fi
# Check if the common document configuration is present, if not clone it
if [ -d "${UT_CORE_PATH}" ]; then
    echo "executing UT-core makefile"
    pushd ${SCRIPTDIR} > /dev/null
    make -C . -f Makefile $@ 
    popd > /dev/null       
else
    echo "Cloning Unit Test Core System - Path "
    pushd "${SCRIPTDIR}" > /dev/null
    git clone ${TEST_REPO} ${UT_CORE_PATH}
    popd > /dev/null    
    pushd "${UT_CORE_PATH}" > /dev/null
    echo "${UT_CORE_PATH}"    
    git checkout ${UT_PROJECT_VERSION} 
    popd > /dev/null   
    if [ -d "${UT_CORE_PATH}" ]; then
        pushd "${UT_CORE_PATH}" > /dev/null
        ./build.sh                                              #Clone utcore framework
        popd > /dev/null
        pushd ${SCRIPTDIR} > /dev/null 
        make -C . -f Makefile $@
        popd > /dev/null 
    fi
    ##./${0} $@ # Commented to avoid server lock by recursive call, when clone is not succeed. 
fi
