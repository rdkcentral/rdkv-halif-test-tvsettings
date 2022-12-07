#!/usr/bin/env bash

# Clone the Unit Testing Suit for this repo, it follows a standard convention
# HAL Name is replaced with haltest, allowing this script to be part of the template for all

# This will look up the last tag in the git repo, depending on the project this may require modification
#TEST_REPO=$(git remote -vv | head -n1 | awk -F ' ' '{print $2}' | sed 's/hal/haltest/g')

#Below link to be changed once master is ready
TEST_REPO="https://github.com/comcast-sky/rdk-components-haltest-tvsettings"

UT_BRANCH_VERSION=RDK-38603_CunitFramework_Tvsettings_HAL

# Set default UT_BRANCH_VERSION to master
if [ -z "${UT_BRANCH_VERSION}" ]; then
    UT_BRANCH_VERSION=master
fi

SCRIPTDIR=${BASH_SOURCE[0]%/*} #$(pwd) #get data from running script file.
#SCRIPTDIR="$( cd "$( dirname "$0" )" && pwd )"

UT_DIR=${SCRIPTDIR}/ut

# Simple help
if [ "${1}" == "-h" ]; then
    echo "Script to build the unit testing suite"
    echo " build_ut.sh <clean> - clean the testing"
    echo " build_ut.sh TARGET=xxx - build the xxx version of the tests, linux/arm etc."
    echo " build_ut.sh <noswitch> - build the linux version of tests using skeleton & stubs"
    exit 0
fi

PARAMETER_1=${1}
echo "PARAM:${PARAMETER_1%=*}"
echo "VALUE:${PARAMETER_1#*=}"
IsTarget=${PARAMETER_1%=*} 
echo $IsTarget

if [ "$IsTarget" = "TARGET" ]
then
    TARGET=${PARAMETER_1#*=}
    echo "Param1 is contains value as TARGET=xxx"
    echo $TARGET
else
    echo "Param1 is not contains value as TARGET=xxx"
fi

export TARGET

# Check if the common document configuration is present, if not clone it
if [ -d "${UT_DIR}" ]; then
    echo "Compiling unit Test for this module"
    pushd "${UT_DIR}" > /dev/null
    ./build.sh $@
    popd > /dev/null
else
    echo "Cloning unit Test Suite for this module"
    pushd "${SCRIPTDIR}" > /dev/null
    git clone ${TEST_REPO} ${UT_DIR}
    popd > /dev/null
    pushd "${UT_DIR}" > /dev/null
    git checkout ${UT_BRANCH_VERSION}
    popd > /dev/null
    source ${UT_DIR}/build.sh $@
    # ./${0} $@   #Commented to avoid server lock by recursive call, when clone is not succeed..
fi
