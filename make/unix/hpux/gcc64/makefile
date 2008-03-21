##
# @file
#
# Makefile for the Demo C++ Framework project
#     - GNU C++ (GCC) compiler (HP-Unix 64-bit).
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
# CXXFLAGS_TARGET_MT := -threads

# Include default GCC definitions.
include ../../../setup/gcc.ini


# Include parent definitions.
include ../system.ini

# Start parent make.
include ../system.mak

# EOF #
