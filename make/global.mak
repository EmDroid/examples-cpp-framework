##
# @file
#
# Makefile for the Demo C++ Framework project - Global makefile.
#
# @author Emil Maskovsky
#
# @warning
# Do not call this make directly, call 'make' in the (platform)/(compiler)
# base directory.
#
# @note
# Processing of dependencies is not supported in this demo library.
#
# @note
# Precompiled headers support is not available in this demo library.
#
# @note
# Smart build of dependent projects is not supported in this demo library.
# Dependent projects are projects, which use this library. Smart build is the
# build of these dependent projects inside this makefile system, so it is not
# needed to provide another makefile set for the dependent project, but only
# simple makefile instead, which sets some variables (EXE or DLL name, source
# files list etc.) and calls the library makefile, which then provides all
# necessary rules to build the final application (including dependency
# processing, precompiled headers etc.).
#
# Possible make targets:
# @li @b all - Build all targets (for all configurations).
# @li @c test - Build targets, tests and run the tests.
# @li @c clean - Clean the build, except main targets.
# @li @c cleanall - Clean the build, including main targets.
#
# Library configurations:
# @li @b lib - Build static libraries (single-threaded).
# @li @b libmt - Build static libraries (multi-threaded).
# @li @b dll - Build dynamic libraries (DLLs - always multi-threaded).
#
# Character type configurations:
# @li @b ansi - Build ANSI targets (1-byte characters).
# @li @b unicode - Build UNICODE targets (2-byte characters).
#
# Debug information configurations:
# @li @b debug - Build debug targets (non-optimized, containing debugging
#        information).
# @li @b release - Build release targets (optimized, without debugging
#        information).
#
# The different configurations can be combined together using following scheme:
# [library_type]_[character_type]_[debuginfo_type]
# For example:
# @c make @c dll_release - will build all release DLLs (ANSI+UNICODE)
# @c make @c unicode_debug - will build all targets (lib, libmt, dll) with
#            UNICODE character type, containing debugging information
# @c make @c lib_ansi - will build all libraries with ANSI character type
#            (DEBUG+RELEASE)
# @c make @c release - will build all release targets
#            (LIB+LIBMT+DLL, ANSI+UNICODE)
# (any configuration type can be used alone to build all targets of that
# configuration)
#
# The basic targets other than @c all can also be combined with required
# configuration scheme, for example:
# @c make @c test_dll_release - will build and test all release DLLs
#            (ANSI+UNICODE)
# @c make @c clean_debug - will clean all debug targets
# @c make @c cleanall_lib_unicode - will clean UNICODE libraries (DEBUG+RELEASE)
# etc.
#


# The default target.
release:


# Logging of targets (for debug purposes).
# May also be set on the make command line.
# MXCPP_TARGETS_LOG := targets.log
$(if $(strip $(MXCPP_MAKE_DEBUG)),$(eval MXCPP_TARGETS_LOG := targets.log))

$(if $(strip $(MXCPP_TARGETS_LOG)),$(shell $(RM) $(MXCPP_TARGETS_LOG) $(NOOUT) $(NOERROUT)))

# Logging of commands (for debug purposes).
# May also be set on the make command line.
MXCPP_COMMANDS_LOG := build.log
$(if $(strip $(MXCPP_MAKE_DEBUG)),$(eval MXCPP_COMMANDS_LOG := build.log))

$(if $(strip $(MXCPP_COMMANDS_LOG)),$(shell $(RM) $(MXCPP_COMMANDS_LOG) $(NOOUT) $(NOERROUT)))


MXCPP_TEST_LOG := tests.log
$(if $(strip $(MXCPP_TEST_LOG)),$(shell $(RM) $(MXCPP_TEST_LOG) $(NOOUT) $(NOERROUT)))
MXCPP_TEST_LOG_FULL := $(if $(strip $(MXCPP_TEST_LOG)),>>$(MXCPP_TEST_LOG))

MXCPP_COMPILE_LOG := compile
$(if $(strip $(MXCPP_COMPILE_LOG)),$(shell $(RM) $(MXCPP_COMPILE_LOG).out $(NOOUT) $(NOERROUT)))
$(if $(strip $(MXCPP_COMPILE_LOG)),$(shell $(RM) $(MXCPP_COMPILE_LOG).err $(NOOUT) $(NOERROUT)))


# Following definitions are defined here, to allow using of variables defined in
# global.ini inside platform.mak or platform.ini 

# ANSI-C includes.
MXCPP_C_INCLUDE := \
$(CC_INCLUDE)$(subst /,$$(PATH_SEP),$(MXCPP_INCLUDE_ROOT))

# C++ includes.
MXCPP_CXX_INCLUDE := \
$(CXX_INCLUDE)$(MXCPP_INCLUDE_ROOT) \
$(CXX_INCLUDE)$(MXCPP_SRC_ROOT)inc

# Resource includes.
MXCPP_RC_INCLUDE := \
$(RC_INCLUDE)$(MXCPP_SRC_ROOT)inc


# Append platform includes.
$(foreach compiler,$(MXCPP_COMPILERS_LIST),\
	$(if $(strip $(MXCPP_$(compiler)_INCLUDE_PLATFORM)),\
		$(eval MXCPP_$(compiler)_INCLUDE += $(MXCPP_$(compiler)_INCLUDE_PLATFORM))))


# Configuration flags.
MXCPP_CFLAGS := $(CC_COMPILE_ONLY)$(if $(strip $(CFLAGS)), $(strip $(CFLAGS)))$(if $(strip $(MXCPP_C_INCLUDE)), $(strip $(MXCPP_C_INCLUDE)))
MXCPP_CXXFLAGS := $(CXX_COMPILE_ONLY)$(if $(strip $(CXXFLAGS)), $(strip $(CXXFLAGS)))$(if $(strip $(MXCPP_CXX_INCLUDE)), $(strip $(MXCPP_CXX_INCLUDE)))
MXCPP_RCFLAGS := $(strip $(RCFLAGS))$(if $(strip $(MXCPP_RC_INCLUDE)), $(strip $(MXCPP_RC_INCLUDE)))

MXCPP_LIBC_FLAGS := $(LIBC_FLAGS)
MXCPP_DLLC_FLAGS := $(DLLC_FLAGS)
MXCPP_LNKC_FLAGS := $(LNKC_FLAGS)

# Append platform configuration flags.
$(foreach compiler,$(MXCPP_COMPILERS_LIST),\
	$(if $(strip $(MXCPP_$(compiler)FLAGS_PLATFORM)),\
		$(eval MXCPP_$(compiler)FLAGS += $(MXCPP_$(compiler)FLAGS_PLATFORM))))


# Makefile dependencies.
#
# Any change in the makefile initialization files *.ini, will cause full rebuild
# of all objects.
MXCPP_MAKEFILE_DEPS := makefile $(filter %.ini,$(MAKEFILE_LIST))
$(if $(strip $(MXCPP_MAKE_DEBUG)),$(warning MAKEFILE dependencies: $(MXCPP_MAKEFILE_DEPS)))


# Define single build rule.
#
# @param $(1) The rule targets.
# @param $(2) The rule sources.
# @param $(3) The rule identifier.
#
# Both rule targets and rule sources can have multiple items.
# The rule sources (the 2nd parameter) can be empty (the targets cannot be
# empty).
# The rule identifier can be number or any string, to identify, where the rule
# comes from (appears then in the logging file, if $$(MXCPP_TARGETS_LOG) is
# set).
#
# @note
# If the variable $$(MXCPP_TARGETS_LOG) is set to some file name, all created
# rules are logged into that file (for debugging purposes).
define MXCPP_BUILD_RULES_SINGLE_RULE

$(if $(strip $(MXCPP_TARGETS_LOG)),$(shell $(ECHO) ($(3)) $(1): $(2) >> $(MXCPP_TARGETS_LOG)))

$(1): $(2)

endef	# MXCPP_BUILD_RULES_SINGLE_RULE


MXCPP_EMPTY_SPACE :=
MXCPP_EMPTY_SPACE := $(MXCPP_EMPTY_SPACE) $(MXCPP_EMPTY_SPACE)
MXCPP_COMMA := ,

define MXCPP_BUILD_RULES_GROUP

$(eval MXCPP_BUILD_RULES_SRC := $(subst $(MXCPP_EMPTY_SPACE),$(3),$(strip $(1))))
$(eval MXCPP_BUILD_RULES_TGT := $(subst $(MXCPP_EMPTY_SPACE),$(3),$(strip $(2))))

$(call MXCPP_BUILD_RULES_SINGLE_RULE,$(if $(strip $(MXCPP_BUILD_RULES_SRC)),$(MXCPP_BUILD_RULES_SRC),all),$(MXCPP_BUILD_RULES_TGT),$(4))

$(call MXCPP_BUILD_RULES_SINGLE_RULE,$(if $(strip $(MXCPP_BUILD_RULES_SRC)),test$(3)$(MXCPP_BUILD_RULES_SRC) $(MXCPP_BUILD_RULES_SRC)$(3)test,test),test_$(MXCPP_BUILD_RULES_TGT),$(4))
$(if $(strip $(3)),,$(call MXCPP_BUILD_RULES_SINGLE_RULE,test_$(MXCPP_BUILD_RULES_SRC) $(MXCPP_BUILD_RULES_SRC)_test,test_$(MXCPP_BUILD_RULES_TGT),$(4)))

$(foreach cleantype,clean cleanall,$(call MXCPP_BUILD_RULES_SINGLE_RULE,$(if $(strip $(MXCPP_BUILD_RULES_SRC)),$(cleantype)_$(MXCPP_BUILD_RULES_SRC),$(cleantype)),$(cleantype)_$(MXCPP_BUILD_RULES_TGT),$(4)))

endef	# MXCPP_BUILD_RULES_GROUP



MXCPP_MAKE_DIR := $(CURDIR)


# Run single build command.
#
# This is convenience macro for running build commands, to allow simple
# logging of commands.
#
# @param $(1) The build command, which would be processed.
# @param $(2) [optional] The command error ignore modifier.
# @param $(3) [optional] Command output redirection (e.g. '>NUL').
#
define MXCPP_RUN_COMMAND
ifneq ($(strip $(MXCPP_COMMANDS_LOG)),)
	-@$(ECHO) $(1) >>$(MXCPP_COMMANDS_LOG)
endif
	$(2)@$(1) $(3)

endef	# MXCPP_RUN_COMMAND
# Warning: Do not remove the empty line at before the endef directive, otherwise
#          the if-endif block will not work inside $(foreach ...) loops!


# Construct build rules for building single object from single source file.
#
# @param $(1) The source files root.
# @param $(2) The source file name, relative to $(1).
# @param $(3) The destination type identifier.
# @param $(4) The object files destination folder.
# @param $(5) The extra build flags.
# @param $(6) The extra parameters for destination build command, separed by
#             commas (build configuration list in most cases).
#
define MXCPP_BUILD_RULES_OBJECT

$(eval MXCPP_SOURCE_SUFFIX := $(suffix $(2)))

$(if $(strip $(findstring $(MXCPP_SOURCE_SUFFIX),.c)),$(eval MXCPP_COMPILER_TYPE := CC),\
$(if $(strip $(findstring $(MXCPP_SOURCE_SUFFIX),.cpp .cxx .c++)),$(eval MXCPP_COMPILER_TYPE := CXX),\
$(if $(strip $(findstring $(MXCPP_SOURCE_SUFFIX),.rc)),$(eval MXCPP_COMPILER_TYPE := RC),\
$(error ERROR: Unsupported source file type 'MXCPP_SOURCE_SUFFIX' (source file: $(2)))\
)))

$(eval MXCPP_OBJECT := $(subst /,$(PATH_SEP),$(4)$(PATH_SEP)$(basename $(notdir $(2)))).$($(3)_SFX))

$(if $(strip $(MXCPP_MAKE_DEBUG)),$(warning SOURCE: $(1)$(2)))
$(if $(strip $(MXCPP_MAKE_DEBUG)),$(warning OBJECT: $(MXCPP_OBJECT)))

$(if $(findstring $(MXCPP_OBJECT),$(MXCPP_BUILD_$(3)_LIST)),$(error ERROR: Object ambiquity. Files listed in MXCPP_SRC_LIST must have different base names, to avoid object names ambiquity (source file: $(2))))

$(eval MXCPP_BUILD_$(3)_LIST += $(MXCPP_OBJECT))

$(eval MXCPP_COMPILE_RULE := $$(call MXCPP_COMPILE_$(MXCPP_COMPILER_TYPE),$(1)$(2),$(5),$(6)))

$(call MXCPP_BUILD_RULES_SINGLE_RULE,$(MXCPP_OBJECT),$$(MXCPP_MAKEFILE_DEPS) $(1)$(2),B)
	@$(ECHO) == $2 ...
	$(if $(strip $($(MXCPP_COMPILER_TYPE)_USE_RESPONSE_FILE)),@$(ECHO) $(MXCPP_COMPILE_RULE) >$(MXCPP_RESPONSE_FILE))
$(call MXCPP_RUN_COMMAND,$($(MXCPP_COMPILER_TYPE)) $(if $(strip $($(MXCPP_COMPILER_TYPE)_USE_RESPONSE_FILE)),@$(MXCPP_RESPONSE_FILE),$(MXCPP_COMPILE_RULE)),,\
		$(if $(strip $(MXCPP_COMPILE_LOG)),>>$(MXCPP_COMPILE_LOG).out 2>>$(MXCPP_COMPILE_LOG).err))
	$(if $(strip $($(MXCPP_COMPILER_TYPE)_USE_RESPONSE_FILE)),@$(RM) $(MXCPP_RESPONSE_FILE))

endef	# MXCPP_BUILD_RULES_OBJECT


# Construct build rules for building single test executable from single source file.
#
# @param $(1) The source file name, relative to the $(MXCPP_TEST_ROOT).
# @param $(2) The destination folder.
# @param $(3) The extra build flags.
# @param $(4) The configuration base (test_...).
# @param $(5) The library configuration.
# @param $(6) The extra parameters for destination build command, separed by
#             commas (build configuration list in most cases, without library
#             configuration).
#
define MXCPP_BUILD_RULES_TEST

$(eval MXCPP_TEST := $(4)_$(basename $(notdir $(1))))
$(eval MXCPP_TEST_EXE := $(subst /,$(PATH_SEP),$(2)$(PATH_SEP)$(basename $(notdir $(1))))$(EXE_SFX))

$(if $(findstring $(MXCPP_TEST),$(MXCPP_BUILD_TEST_LIST)),$(error ERROR: Test ambiquity. Files listed in MXCPP_TEST_LIST must have different base names, to avoid test names ambiquity (source file: $(1))))

$(eval MXCPP_BUILD_TEST_LIST += $(MXCPP_TEST))

$(call MXCPP_BUILD_RULES_SINGLE_RULE,$(MXCPP_TEST),$(MXCPP_TEST_EXE),C)
	@$(ECHO) +++ Running $1 test ...
$(call MXCPP_RUN_COMMAND,$(MXCPP_TEST_EXE),,$(if $(strip $(MXCPP_TEST_LOG)),>>$(MXCPP_TEST_LOG)))

$(call MXCPP_BUILD_RULES_OBJECT,$(MXCPP_TEST_ROOT),$(1),OBJ,$(2),$(3),$(5)$(MXCPP_COMMA)$(6))

$(eval MXCPP_BUILD_RULE := $$(call MXCPP_BUILD_EXE,$(LNKC_OBJ)$(MXCPP_OBJECT),,$(MXCPP_LIBS) $(MXCPP_BUILD_LIBS),$(6)))

$(call MXCPP_BUILD_RULES_SINGLE_RULE,$(MXCPP_TEST_EXE),$(MXCPP_TARGET_LIBRARY) $(MXCPP_OBJECT),C)
	@$$(ECHO) == linking [$$@] ...
	$(if $(strip $(LNKC_USE_RESPONSE_FILE)),@$(ECHO) $(MXCPP_BUILD_RULE) >$(MXCPP_RESPONSE_FILE))
$(call MXCPP_RUN_COMMAND,$(LNKC) $(if $(strip $(LNKC_USE_RESPONSE_FILE)),@$(MXCPP_RESPONSE_FILE),$(MXCPP_BUILD_RULE)))
	$(if $(strip $(LNKC_USE_RESPONSE_FILE)),@$(RM) $(MXCPP_RESPONSE_FILE))

endef	# MXCPP_BUILD_RULES_TEST


# Build final rules for single library and build configuration.
#
# @param $(1) The library configuration.
# @param $(2) The build configuration (without library config).
#
define MXCPP_BUILD_RULES_FINAL

$(eval MXCPP_BUILD_RULES_LIBRARY := $(strip $(1)))
$(eval MXCPP_BUILD_RULES_CONFIGURATION := $(strip $(2)))
$(eval MXCPP_BUILD_RULES_SRC := $(subst $(MXCPP_EMPTY_SPACE),_,$(MXCPP_BUILD_RULES_LIBRARY) $(MXCPP_BUILD_RULES_CONFIGURATION)))

$(eval MXCPP_BUILD_RULES_CONFIGURATION_COMMA := $(subst $(MXCPP_EMPTY_SPACE),$(MXCPP_COMMA),$(MXCPP_BUILD_RULES_CONFIGURATION)))
$(eval MXCPP_BUILD_RULES_CONFIGURATION := $(subst $(MXCPP_EMPTY_SPACE),-,$(MXCPP_BUILD_RULES_CONFIGURATION)))

$(eval MXCPP_OBJECT_DIR := obj)
$(foreach modifier,$(2),$(eval MXCPP_OBJECT_DIR += $(MXCPP_MOD_$(modifier))))
$(eval MXCPP_OBJECT_DIR += $(MXCPP_MOD_$(1)))
$(eval MXCPP_OBJECT_DIR := $(subst $(MXCPP_EMPTY_SPACE),,$(MXCPP_OBJECT_DIR)))

$(if $(strip $(MXCPP_DLLCONFIG_$(1))),\
$(eval MXCPP_BUILD_EXTRA_FLAGS := $(if $(strip $(CFLAGS_DLL_DLL)),$(CFLAGS_DLL_DLL) )$(CC_DEFINE)MXCPP_MAKEDLL),\
$(eval MXCPP_BUILD_EXTRA_FLAGS :=))

$(eval MXCPP_BUILD_OBJ_LIST :=)
$(foreach srcfile,$(MXCPP_SRC_LIST),$(call MXCPP_BUILD_RULES_OBJECT,$(MXCPP_SRC_ROOT),$(srcfile),OBJ,$(MXCPP_OBJECT_DIR),$(MXCPP_BUILD_EXTRA_FLAGS),$(1)$(MXCPP_COMMA)$(MXCPP_BUILD_RULES_CONFIGURATION_COMMA)))

$(if $(strip $(MXCPP_MAKE_DEBUG)),$(warning MXCPP_BUILD_OBJ_LIST: $(MXCPP_BUILD_OBJ_LIST)))

$(if $(strip $(MXCPP_DLLCONFIG_$(1))),\
$(eval MXCPP_LINKER_TYPE := DLLC),\
$(eval MXCPP_LINKER_TYPE := LIBC))

$(eval MXCPP_BUILD_OBJ_LIST_LINKER :=)
$(foreach object,$(MXCPP_BUILD_OBJ_LIST),$(eval MXCPP_BUILD_OBJ_LIST_LINKER += $($(MXCPP_LINKER_TYPE)_OBJ)$(object)))

$(eval MXCPP_BUILD_RES_LIST :=)
$(if $(strip $(MXCPP_DLLCONFIG_$(1))),\
$(if $(strip $(RC)),\
	$(foreach resfile,$(MXCPP_RES_LIST),$(call MXCPP_BUILD_RULES_OBJECT,$(MXCPP_RES_ROOT),$(resfile),RES,$(MXCPP_OBJECT_DIR),,$(MXCPP_BUILD_RULES_CONFIGURATION_COMMA)))))

$(if $(strip $(MXCPP_MAKE_DEBUG)),$(warning MXCPP_BUILD_RES_LIST: $(MXCPP_BUILD_RES_LIST)))

$(eval MXCPP_BUILD_RES_LIST_LINKER :=)
$(foreach object,$(MXCPP_BUILD_RES_LIST),$(eval MXCPP_BUILD_RES_LIST_LINKER += $(DLLC_RES)$(object)))


$(eval MXCPP_TARGET_SUBTYPE_MOD :=)
$(foreach subtype,$(2),$(eval MXCPP_TARGET_SUBTYPE_MOD += $(MXCPP_MOD_$(subtype))))
$(eval MXCPP_TARGET_SUBTYPE_MOD := $(subst $(MXCPP_EMPTY_SPACE),,$(MXCPP_TARGET_SUBTYPE_MOD)))

$(eval MXCPP_TARGET_LIBRARY := $(call MXCPP_$(1)_CONSTRUCT_FULLNAME,$(MXCPP_TARGET_SUBTYPE_MOD)))
$(if $(strip $(MXCPP_MAKE_DEBUG)),$(warning MXCPP_TARGET_LIBRARY: "$(MXCPP_TARGET_LIBRARY)"))

$(if $(strip $(MXCPP_DLLCONFIG_$(1))),\
$(if $(strip $(LN)),$(eval MXCPP_TARGET_LIBRARY_SIMPLE_NAME :=)\
	$(eval MXCPP_TARGET_LIBRARY_SIMPLE_NAME := $(call MXCPP_$(1)_CONSTRUCT_FULLNAME_SIMPLE,$(MXCPP_TARGET_SUBTYPE_MOD)))))


$(eval MXCPP_BUILD_LIBS := $(LNKC_LIB_PFX)$(call MXCPP_$(1)_CONSTRUCT_NAME,$(MXCPP_TARGET_SUBTYPE_MOD))$(LNKC_LIB_SFX))

$(if $(strip $(MXCPP_DLLCONFIG_$(1))),\
$(eval MXCPP_BUILD_RULE := $$(call MXCPP_BUILD_DLL,$(MXCPP_BUILD_OBJ_LIST_LINKER),$(MXCPP_BUILD_RES_LIST_LINKER),$(MXCPP_LIBS),$(MXCPP_BUILD_RULES_CONFIGURATION_COMMA))),\
$(eval MXCPP_BUILD_RULE := $$(call MXCPP_BUILD_LIB,$(MXCPP_BUILD_OBJ_LIST_LINKER),$(MXCPP_BUILD_RULES_CONFIGURATION_COMMA))))

$(call MXCPP_BUILD_RULES_SINGLE_RULE,_start_$(MXCPP_BUILD_RULES_SRC),,X)
	@$$(ECHO) Building $(MXCPP_BUILD_RULES_LIBRARY)[$(MXCPP_BUILD_RULES_CONFIGURATION)] ...

$(call MXCPP_BUILD_RULES_SINGLE_RULE,$(MXCPP_BUILD_RULES_SRC),_start_$(MXCPP_BUILD_RULES_SRC) $(MXCPP_TARGET_LIBRARY),X)
	@$$(ECHO) ... building $(MXCPP_BUILD_RULES_LIBRARY)[$(MXCPP_BUILD_RULES_CONFIGURATION)] done.

$(call MXCPP_BUILD_RULES_SINGLE_RULE,$(MXCPP_TARGET_LIBRARY),$(MXCPP_OBJECT_DIR) $(MXCPP_BUILD_OBJ_LIST) $(MXCPP_BUILD_RES_LIST),A)
	@$$(ECHO) == linking [$$@] ...
$(call MXCPP_RUN_COMMAND,$(RM) $$@ $(MXCPP_TARGET_LIBRARY_SIMPLE_NAME),-,$(NOERROUT))
	$(if $(strip $($(MXCPP_LINKER_TYPE)_USE_RESPONSE_FILE)),@$(ECHO) $(MXCPP_BUILD_RULE) >$(MXCPP_RESPONSE_FILE))
$(call MXCPP_RUN_COMMAND,$($(MXCPP_LINKER_TYPE)) $(if $(strip $($(MXCPP_LINKER_TYPE)_USE_RESPONSE_FILE)),@$(MXCPP_RESPONSE_FILE),$(MXCPP_BUILD_RULE)))
	$(if $(strip $($(MXCPP_LINKER_TYPE)_USE_RESPONSE_FILE)),@$(RM) $(MXCPP_RESPONSE_FILE))
$(if $(strip $(MXCPP_DLLCONFIG_$(1))),$(if $(strip $(DLLC_IMPLIB)),\
	$(call MXCPP_RUN_COMMAND,$(DLLC_IMPLIB) $(DLLC_IMPLIB_FLAGS) $(DLLC_IMPLIB_OUT)$$(@:.dll=.lib) $$@)))
$(if $(strip $(MXCPP_TARGET_LIBRARY_SIMPLE_NAME)),\
	$(call MXCPP_RUN_COMMAND,$(call LN,$$@,$(MXCPP_TARGET_LIBRARY_SIMPLE_NAME))))

$(eval MXCPP_OBJECT_DIR_TEST := $(MXCPP_OBJECT_DIR)$(PATH_SEP)test)

$(if $(strip $(MXCPP_DLLCONFIG_$(1))),\
$(eval MXCPP_BUILD_EXTRA_FLAGS := $(if $(strip $(CFLAGS_DLL_EXE)),$(CFLAGS_DLL_EXE) )$(CC_DEFINE)MXCPP_USEDLL),\
$(eval MXCPP_BUILD_EXTRA_FLAGS :=))

$(eval MXCPP_BUILD_OBJ_LIST :=)
$(eval MXCPP_BUILD_TEST_LIST :=)
$(foreach testfile,$(MXCPP_TEST_LIST),$(call MXCPP_BUILD_RULES_TEST,$(testfile),$(MXCPP_OBJECT_DIR_TEST),$(MXCPP_BUILD_EXTRA_FLAGS),test_$(MXCPP_BUILD_RULES_SRC),$(1),$(MXCPP_BUILD_RULES_CONFIGURATION_COMMA)))

$(if $(strip $(MXCPP_MAKE_DEBUG)),$(warning MXCPP_BUILD_TEST_LIST: $(MXCPP_BUILD_TEST_LIST)))

$(call MXCPP_BUILD_RULES_SINGLE_RULE,_start_test_$(MXCPP_BUILD_RULES_SRC),,X)
	@$$(ECHO) Testing $(MXCPP_BUILD_RULES_LIBRARY)[$(MXCPP_BUILD_RULES_CONFIGURATION)] ...

$(call MXCPP_BUILD_RULES_SINGLE_RULE,test_$(MXCPP_BUILD_RULES_SRC) $(MXCPP_BUILD_RULES_SRC)_test,$(MXCPP_BUILD_RULES_SRC) _start_test_$(MXCPP_BUILD_RULES_SRC) $(MXCPP_OBJECT_DIR_TEST) $(MXCPP_BUILD_TEST_LIST),X)
	@$$(ECHO) ... testing $(MXCPP_BUILD_RULES_LIBRARY)[$(MXCPP_BUILD_RULES_CONFIGURATION)] done.

$(call MXCPP_BUILD_RULES_SINGLE_RULE,_start_clean_$(MXCPP_BUILD_RULES_SRC),,X)
	@$$(ECHO) Cleaning $(MXCPP_BUILD_RULES_LIBRARY)[$(MXCPP_BUILD_RULES_CONFIGURATION)] ...

$(call MXCPP_BUILD_RULES_SINGLE_RULE,clean_$(MXCPP_BUILD_RULES_SRC),_start_clean_$(MXCPP_BUILD_RULES_SRC) _make_clean_$(MXCPP_BUILD_RULES_SRC),X)
	@$$(ECHO) ... cleaning $(MXCPP_BUILD_RULES_LIBRARY)[$(MXCPP_BUILD_RULES_CONFIGURATION)] done.

$(call MXCPP_BUILD_RULES_SINGLE_RULE,_start_cleanall_$(MXCPP_BUILD_RULES_SRC),,X)
	@$$(ECHO) Cleaning all $(MXCPP_BUILD_RULES_LIBRARY)[$(MXCPP_BUILD_RULES_CONFIGURATION)] ...

$(call MXCPP_BUILD_RULES_SINGLE_RULE,cleanall_$(MXCPP_BUILD_RULES_SRC),_start_cleanall_$(MXCPP_BUILD_RULES_SRC) _make_cleanall_$(MXCPP_BUILD_RULES_SRC),X)
	@$$(ECHO) ... cleaning all $(MXCPP_BUILD_RULES_LIBRARY)[$(MXCPP_BUILD_RULES_CONFIGURATION)] done.

$(call MXCPP_BUILD_RULES_SINGLE_RULE,_make_clean_$(MXCPP_BUILD_RULES_SRC),,X)
$(if $(strip $(MXCPP_COMPILE_LOG)),$(call MXCPP_RUN_COMMAND,$(RM) $(MXCPP_COMPILE_LOG).out,-,$(NOERROUT)))
$(if $(strip $(MXCPP_COMPILE_LOG)),$(call MXCPP_RUN_COMMAND,$(RM) $(MXCPP_COMPILE_LOG).err,-,$(NOERROUT)))
$(if $(strip $(MXCPP_TEST_LOG)),$(call MXCPP_RUN_COMMAND,$(RM) $(MXCPP_TEST_LOG),-,$(NOERROUT)))
$(if $(strip $(MXCPP_RESPONSE_FILE)),$(call MXCPP_RUN_COMMAND,$(RM) $(MXCPP_RESPONSE_FILE),-,$(NOERROUT)))
$(if $(strip $(OBJ_SFX)),$(call MXCPP_RUN_COMMAND,$(RM) $(MXCPP_OBJECT_DIR)$(PATH_SEP)*.$(OBJ_SFX),-,$(NOERROUT)))
$(if $(strip $(MXCPP_DLLCONFIG_$(1))),$(if $(strip $(RES_SFX)),\
	$(call MXCPP_RUN_COMMAND,$(RM) $(MXCPP_OBJECT_DIR)$(PATH_SEP)*.$(RES_SFX),-,$(NOERROUT))))
$(foreach libtype,0 $(1),\
$(foreach config,0 $(2),\
$(foreach cleanitem,\
	$(call MXCPP_CLEAN_MASK$(if $(strip $(filter-out 0,$(libtype))),_$(libtype))$(if $(strip $(filter-out 0,$(config))),_$(config)),\
		$(MXCPP_OBJECT_DIR)$(PATH_SEP),$(MXCPP_TARGET_LIBRARY)),\
	$(call MXCPP_RUN_COMMAND,$(RM) $(cleanitem),-,$(NOERROUT)))))
$(foreach libtype,0 $(1),\
$(foreach config,0 $(2),\
$(foreach cleanitem,\
	$(call MXCPP_CLEAN_MASK_TEST$(if $(strip $(filter-out 0,$(libtype))),_$(libtype))$(if $(strip $(filter-out 0,$(config))),_$(config)),\
		$(MXCPP_OBJECT_DIR_TEST)$(PATH_SEP)),\
	$(call MXCPP_RUN_COMMAND,$(RM) $(cleanitem),-,$(NOERROUT)))))
$(call MXCPP_RUN_COMMAND,$(RM) $(MXCPP_OBJECT_DIR_TEST)$(PATH_SEP)*.$(OBJ_SFX),-,$(NOERROUT))
$(call MXCPP_RUN_COMMAND,$(RM) $(MXCPP_OBJECT_DIR_TEST)$(PATH_SEP)*$(EXE_SFX),-,$(NOERROUT))
$(call MXCPP_RUN_COMMAND,$(RMDIR) $(MXCPP_OBJECT_DIR_TEST),-,$(NOERROUT))
$(call MXCPP_RUN_COMMAND,$(RMDIR) $(MXCPP_OBJECT_DIR),-,$(NOERROUT))

$(call MXCPP_BUILD_RULES_SINGLE_RULE,_make_cleanall_$(MXCPP_BUILD_RULES_SRC),_make_clean_$(MXCPP_BUILD_RULES_SRC),X)
$(call MXCPP_RUN_COMMAND,$(RM) $(MXCPP_TARGET_LIBRARY) $(MXCPP_TARGET_LIBRARY_SIMPLE_NAME),-,$(NOERROUT))
$(foreach libtype,0 $(1),\
$(foreach config,0 $(2),\
$(foreach cleanitem,\
	$(call MXCPP_CLEANALL_MASK$(if $(strip $(filter-out 0,$(libtype))),_$(libtype))$(if $(strip $(filter-out 0,$(config))),_$(config)),\
		$(MXCPP_OBJECT_DIR)$(PATH_SEP),$(MXCPP_TARGET_LIBRARY)),\
	$(call MXCPP_RUN_COMMAND,$(RM) $(cleanitem),-,$(NOERROUT)))))

$(call MXCPP_BUILD_RULES_SINGLE_RULE,$(MXCPP_OBJECT_DIR) $(MXCPP_OBJECT_DIR_TEST),,X)
$(call MXCPP_RUN_COMMAND,$(MKDIR) $$@)

endef	# MXCPP_BUILD_RULES_FINAL


define MXCPP_BUILD_RULES_SHARE_CHARTYPE_DBGINFO

$(foreach subtype,$(3) $(2),$(call MXCPP_BUILD_RULES_GROUP,$(1) $(subtype),$(1) $(2) $(3),_,2))

$(call MXCPP_BUILD_RULES_GROUP,$(2) $(3),$(1) $(2) $(3),_,3)

$(call MXCPP_BUILD_RULES_FINAL,$(1),$(2) $(3))

endef	# MXCPP_BUILD_RULES_SHARE_CHARTYPE_DBGINFO


define MXCPP_BUILD_RULES_SHARE_CHARTYPE

$(foreach subtype,$(1) $(2),$(call MXCPP_BUILD_RULES_GROUP,$(subtype),$(1) $(2),_,1))

$(foreach dbgtype,$(MXCPP_TARGET_SUBTYPE_DBGINFO),$(call MXCPP_BUILD_RULES_SHARE_CHARTYPE_DBGINFO,$(1),$(2),$(dbgtype)))

endef	# MXCPP_BUILD_RULES_SHARE_CHARTYPE


define MXCPP_BUILD_RULES_SHARE_DBGINFO

$(call MXCPP_BUILD_RULES_GROUP,$(2),$(1) $(2),_,1)

endef	# MXCPP_BUILD_RULES_SHARE_DBGINFO


define MXCPP_BUILD_RULES_SHARE

$(call MXCPP_BUILD_RULES_GROUP,,$(1),_,0)

$(foreach chartype,$(MXCPP_TARGET_SUBTYPE_CHARTYPE),$(call MXCPP_BUILD_RULES_SHARE_CHARTYPE,$(1),$(chartype)))
$(foreach dbgtype,$(MXCPP_TARGET_SUBTYPE_DBGINFO),$(call MXCPP_BUILD_RULES_SHARE_DBGINFO,$(1),$(dbgtype)))

endef	# MXCPP_BUILD_RULES_SHARE


$(foreach sharetype,$(MXCPP_TARGET_TYPE_SHARE),$(eval $(call MXCPP_BUILD_RULES_SHARE,$(sharetype))))


# EOF #
