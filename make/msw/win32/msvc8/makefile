##
# @file
#
# Makefile for the Demo C++ Framework project
#     - Microsoft Visual C++ 8.0 compiler (Windows 32-bit).
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


CXXFLAGS_DEBUG_EXTRA := -Zi -RTCsu

# MT runtime always used.
# (ML runtime deprecated)
CXXFLAGS_LIB_RUNTIME := -MT
CXXFLAGS_LIBMT_RUNTIME := -MT

# MSVC database name.
CXXFLAGS_VCDB_NAME := vc80

# Linker target flags.
LDFLAGS_TARGET := /machine:I386


# Include default MSVC definitions.
include ../../setup/msvc.ini


# Addditional clean masks for 'clean...' targets.
MXCPP_CLEAN_MASK_TEST += $(1)*.manifest

# Addditional clean masks for 'cleanall...' targets.
MXCPP_CLEANALL_MASK_DLL += $(2).manifest


# Include parent definitions.
include ../system.ini

# Start parent make.
include ../system.mak

# EOF #
