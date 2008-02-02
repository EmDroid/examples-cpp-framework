# $Id$ #

##
# @file
#
# Makefile for the Demo C++ Framework project
#     - Microsoft Visual C++ 7.0 compiler (Windows 64-bit).
#
# @author Emil Maskovsky
#


define MXCPP_GMAKE_OLD

$(warning /==================================================\)
$(warning |                 !!! ERROR !!!                    |)
$(warning |--------------------------------------------------|)
$(warning |     !!! Incompatible MAKE tool detected !!!      |)
$(warning |  This build system requires "GNU make" tool, at  |)
$(warning |  least the version 3.81 (try 'make --version')   |)
$(warning \==================================================/)

endef

# Check the $(MAKE) version compatibility.
$(if $(strip $(MAKEFILE_LIST)),,$(eval $(call MXCPP_GMAKE_OLD)))


CXXFLAGS_DEBUG_EXTRA := -Zi
# -RTCsu
# /RTC not working for now - some problems with libraries
# (unresolved RTC_Shutdown etc.)

# DLL runtime always used.
# (ML and MT runtimes deprecated)
CXXFLAGS_LIB_RUNTIME := -MD
CXXFLAGS_LIBMT_RUNTIME := -MD

# MSVC database name.
CXXFLAGS_VCDB_NAME := vc70

# Linker target flags.
LDFLAGS_TARGET := /machine:AMD64


# Include default MSVC definitions.
include ../../setup/msvc.ini


# Include parent definitions.
include ../system.ini

# Start parent make.
include ../system.mak

# EOF #
