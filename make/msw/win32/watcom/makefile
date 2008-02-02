##
# @file
#
# Makefile for the Demo C++ Framework project
#     - Open Watcom C++ compiler (Windows 32-bit).
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
CXXFLAGS_TARGET := -bt=nt
CXXFLAGS_MT := -bm
RCFLAGS_TARGET := -bt=nt

# Include default WATCOM definitions.
include ../../setup/watcom.ini


# The linker global flags.
LNKC_FLAGS += system nt
DLLC_FLAGS += system nt_dll


# Include parent definitions.
include ../system.ini

# Start parent make.
include ../system.mak

# EOF #
