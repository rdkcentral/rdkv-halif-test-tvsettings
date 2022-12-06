#* ******************************************************************************
#* Copyright (C) 2022 Sky group of companies, All Rights Reserved
#* * --------------------------------------------------------------------------
#* * THIS SOFTWARE CONTRIBUTION IS PROVIDED ON BEHALF OF SKY PLC. 
#* * BY THE CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
#* * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#* * A PARTICULAR PURPOSE ARE DISCLAIMED
#* ******************************************************************************
#*
#*   ** Project      : ut
#*   ** @addtogroup  : ut
#*   ** @file        : makefile
#*   ** @author      : gerald.weatherup@sky.uk
#*   ** @date        : 20/05/2022
#*   **
#*   ** @brief : Makefile for ut
#*   ** 
#*
#* ******************************************************************************
ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
BIN_DIR := $(ROOT_DIR)/bin
TOP_DIR := $(ROOT_DIR)

SRC_DIRS = $(ROOT_DIR)/src
INC_DIRS := $(ROOT_DIR)/../
INC_DIRS += $(ROOT_DIR)/include

ifeq ($(TARGET),)
$(info TARGET NOT SET )
$(info TARGET FORCED TO Linux)
TARGET=linux
endif


$(info TARGET [$(TARGET)])


ifeq ($(TARGET),linux)
SRC_DIRS += $(ROOT_DIR)/skeletons/src
export CC=g++ 
endif

HAL_LIB_DIR := $(ROOT_DIR)/..
ifeq ($(TARGET),arm)
export CC=arm-rdk-linux-gnueabi-g++  -march=armv7-a -mthumb -mfpu=neon -mfloat-abi=hard --sysroot=$(PKG_CONFIG_SYSROOT_DIR)
YLDFLAGS = -Wl,-rpath,$(HAL_LIB_DIR) -L$(HAL_LIB_DIR) -ltvsettings-hal
endif

.PHONY: clean list all

# Here is a list of exports from this makefile to the next
export YLDFLAGS
export BIN_DIR
export SRC_DIRS
export INC_DIRS
export TARGET
export TOP_DIR
export HAL_LIB_DIR

.PHONY: clean list build

build:
	@echo UT [$@]
	echo "PKG_CONFIG_SYSROOT_DIR"
	echo $(PKG_CONFIG_SYSROOT_DIR)
	make -C ./ut-core

list:
	@echo UT [$@]
	echo "PKG_CONFIG_SYSROOT_DIR"
	echo $(PKG_CONFIG_SYSROOT_DIR)
	make -C ./ut-core list

clean:
	@echo UT [$@]
	echo "PKG_CONFIG_SYSROOT_DIR"
	echo $(PKG_CONFIG_SYSROOT_DIR)
	make -C ./ut-core clean
