##
# @file
#
# Makefile for the Demo C++ Framework project
#     - GNU C++ (GCC) compiler (AIX 64-bit).
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
CFLAGS_TARGET := -maix64
CFLAGS_TARGET_MT := -pthread

# Include default GCC definitions.
include ../../../setup/gcc.ini

# Extra flags.
LNKC_FLAGS_DLL += -Wl,-brtl


# Include parent definitions.
include ../system.ini

# Start parent make.
include ../system.mak

# EOF #
