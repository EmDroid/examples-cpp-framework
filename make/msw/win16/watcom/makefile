##
# @file
#
# Makefile for the Demo C++ Framework project
#     - Open Watcom C++ compiler (Windows 16-bit).
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
CXXFLAGS_TARGET := -mm -bt=windows
RCFLAGS_TARGET := -bt=windows


# Include default WATCOM definitions.
include ../../setup/watcom.ini


# The compiler executable.
CXX := wpp

# Using response file to avoid "line-too-long" problem.
CXX_USE_RESPONSE_FILE := 1


# The linker global flags.
LNKC_FLAGS += system windows

# Flags for different build configurations.
LNKC_FLAGS_DEBUG :=

# The linker global flags.
DLLC_FLAGS += system windows_dll

# Flags for different build configurations.
DLLC_FLAGS_DEBUG := $(LNKC_FLAGS_DEBUG)


# Include parent definitions.
include ../system.ini

# Start parent make.
include ../system.mak

# EOF #
