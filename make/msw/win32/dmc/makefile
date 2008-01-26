##
# @file
#
# Makefile for the Demo C++ Framework project
#     - Digital Mars (DMC) compiler (Windows 32-bit).
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


# The target flags.
CFLAGS_TARGET := -mn

# Flags for different build configurations.
CFLAGS_LIB := -WA
CFLAGS_LIBMT := -WA
CFLAGS_DLL_DLL := -WD
CFLAGS_DLL_EXE := -WA


# Include default DMC definitions.
include ../../setup/dmc.ini


# Include parent definitions.
include ../system.ini

# Start parent make.
include ../system.mak

# EOF #
