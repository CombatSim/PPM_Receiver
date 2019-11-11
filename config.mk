# Name: Makefile_STM
# Author: Daniel Nery Silva de Oliveira
# ThundeRatz Robotics Team
# 06/2019

# Cube file name without .ioc extension
PROJECT_NAME = vr_joystick
VERSION := 1

TARGET_BOARD := target_$(PROJECT_NAME)_$(VERSION)

DEVICE_FAMILY  := STM32F0xx
DEVICE_TYPE    := STM32F072xx
DEVICE_DEF     := STM32F072xB
DEVICE         := STM32F072RB

# Linker script file without .ld extension
# Find it on cube folder after code generation
DEVICE_LD_FILE := STM32F072RBTx_FLASH

# Lib dir
LIB_DIR  := lib

# Cube Directory
CUBE_DIR := cube

# Config Files Directory
CFG_DIR :=

# Tests Directory
TEST_DIR := tests

# Default values, can be set on the command line or here
DEBUG   ?= 1
VERBOSE ?= 0
TEST    ?= 0
