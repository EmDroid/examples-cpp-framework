##
# @file
#
# Makefile for the Demo C++ Framework project
#     - Borland C++ compiler (Windows 32-bit).
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


############################
#     Compiler options     #
############################

# Suffix of object file names.
# (cannot be empty)
OBJ_SFX := obj


# C++ compiler settings.

# The compiler executable.
CXX := bcc32

# The compiler global flags.
# (used standardized name CXXFLAGS, which can be
# overridden on the make command line)
CXXFLAGS := -q -d -x -xd -RT

# Output name flag.
CXX_OUT := -o
# Compile-only flag.
CXX_COMPILE_ONLY := -c
# Macro definition flag.
CXX_DEFINE := -D
# Include directory flag.
CXX_INCLUDE := -I

# Flags for different build configurations.
CXXFLAGS_UNICODE := -WU
CXXFLAGS_DEBUG := -w -Od -v
CXXFLAGS_RELEASE := -w- -O2
# CXXFLAGS_LIB := -WC
# For now, the multithreaded version is always build.
# It is connected with linker configuration.
CXXFLAGS_LIB := -WM
CXXFLAGS_LIBMT := -WM
CXXFLAGS_DLL := -WD -WM


# Resource compiler settings.

# The compiler executable.
RC := brcc32

# Suffix of compiled resource files.
# (cannot be empty, if RC defined)
RES_SFX := res

# The compiler global flags.
# (used standardized name RCFLAGS, which can be
# overridden on the make command line)
RCFLAGS := -32 -iC:\SW\Borland\Bcc55\include

# Output name flag.
RC_OUT := -fo

# Macro definition flag.
RC_DEFINE := -d
# Include directory flag.
RC_INCLUDE := -i


##########################
#     Linker options     #
##########################

# The linker global flags.
# (used standardized name LDFLAGS, which can be
# overridden on the make command line)
LDFLAGS := /q /x /c /Gn

# Suffix of object libraries.
# (cannot be empty)
LIB_SFX := lib


# C++ linker settings.

# The linker executable.
LNKC := ilink32

# The linker build scheme.
LNKC_SCHEME = $(1) c0x32.obj $(3), $(2),, cw32mt.lib import32.lib $(5),, $(4)

# The linker global flags.
# (includes standard name LDFLAGS, which can be
# overridden on the make command line)
LNKC_FLAGS := $(LDFLAGS) /ap /Tpe

# Flags for different build configurations.
LNKC_FLAGS_DEBUG := /v /w
LNKC_FLAGS_RELEASE :=

LNKC_LIB_SFX := .$(LIB_SFX)


# C++ librarian compiler settings.

# The librarian executable.
LIBC := tlib

# The librarian global flags.
LIBC_FLAGS := /P4096 /a

# Output name flag.
LIBC_OUT := 


# C++ dynamic library linker settings.

# The linker executable.
DLLC := $(LNKC)

# The linker build scheme.
DLLC_SCHEME = $(LNKC_SCHEME)
DLLC_SCHEME = $(1) c0d32.obj $(3), $(2),, cw32mt.lib import32.lib $(5),, $(4)

# The linker global flags.
# (includes standard name LDFLAGS, which can be
# overridden on the make command line)
DLLC_FLAGS := $(LDFLAGS) /aa /Tpd

# Flags for different build configurations.
DLLC_FLAGS_DEBUG := $(LNKC_FLAGS_DEBUG)
DLLC_FLAGS_RELEASE := $(LNKC_FLAGS_RELEASE)

# Tool for creating the import library from the DLL.
DLLC_IMPLIB := implib
DLLC_IMPLIB_FLAGS := 
DLLC_IMPLIB_OUT := 


# Addditional clean masks for 'clean...' targets.
MXCPP_CLEAN_MASK = *.bak
MXCPP_CLEAN_MASK_DEBUG = 
MXCPP_CLEAN_MASK_TEST = $(1)*.tds
MXCPP_CLEAN_MASK_TEST_DEBUG = 

# Addditional clean masks for 'cleanall...' targets.
MXCPP_CLEANALL_MASK_DLL = $(2:.dll=.lib) $(2:.dll=.tds)
MXCPP_CLEANALL_MASK_DLL_DEBUG = 


# Include parent definitions.
include ../system.ini

# Start parent make.
include ../system.mak

# EOF #
