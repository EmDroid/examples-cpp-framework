##
# @file
#
# Makefile for the Demo C++ Framework project
#     - Digital Mars (DMC) compiler (DOS 32-bit extender).
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
CXXFLAGS_TARGET := -mxd

# Include default DMC definitions.
include ../../setup/dmc.ini


# Using response file to avoid "line-too-long" problem.
CXX_USE_RESPONSE_FILE := 1
LNKC_USE_RESPONSE_FILE := $(CXX_USE_RESPONSE_FILE)

# The target flags.
LNKC_FLAGS += x32.lib


# Include parent definitions.
include ../system.ini

# Start parent make.
include ../system.mak

# EOF #
