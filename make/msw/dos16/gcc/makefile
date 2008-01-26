##
# @file
#
# Makefile for the Demo C++ Framework project
#     - GNU C++ (GCC) compiler (DOS 16-bit - DJGPP).
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


# Include default GCC definitions.
include ../../../setup/gcc.ini


# The compiler executable.
CC := gxx
# For now, for the DJGPP is used the gxx even for ANSI-C compiling, to avoid
# confusion between DJGPP and MinGW in batch processing mode for all MSW
# platforms.

# Using response file to avoid "line-too-long" problem.
CC_USE_RESPONSE_FILE := 1

# The compiler executable.
CXX := $(CC)

# Using response file to avoid "line-too-long" problem.
CXX_USE_RESPONSE_FILE := $(CC_USE_RESPONSE_FILE)


# The linker executable.
LNKC := $(CXX)

# Using response file to avoid "line-too-long" problem.
LNKC_USE_RESPONSE_FILE := $(CXX_USE_RESPONSE_FILE)


# Include parent definitions.
include ../system.ini

# Start parent make.
include ../system.mak

# EOF #
