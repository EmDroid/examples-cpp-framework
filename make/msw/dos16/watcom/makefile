##
# @file
#
# Makefile for the Demo C++ Framework project
#     - Open Watcom C++ compiler (DOS 16-bit).
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
CXXFLAGS_TARGET := -mm -bt=dos


# Include default WATCOM definitions.
include ../../setup/watcom.ini


# The compiler executable.
CXX := wpp

# Using response file to avoid "line-too-long" problem.
CXX_USE_RESPONSE_FILE := 1


# The linker global flags.
LNKC_FLAGS += system dos option stack=4k


# Include parent definitions.
include ../system.ini

# Start parent make.
include ../system.mak

# EOF #
