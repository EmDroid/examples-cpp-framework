

# The default target.
release:


# Uncomment following line, if you wisch to debug the build make system.
# The MXCPP_MAKE_DEBUG can also be set on the make command line.
# MXCPP_MAKE_DEBUG := 1

# Allow the value '0' for disabling the debug.
# 'override' directive for working even for make command line.
override MXCPP_MAKE_DEBUG := $(filter-out 0,$(MXCPP_MAKE_DEBUG))

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


# Following definitions are defined here, to allow using of variables defined in
# global.ini inside platform.mak or platform.ini 

# ANSI-C includes.
MXCPP_C_INCLUDE := \
$(CC_INCLUDE)$(MXCPP_INCLUDE_ROOT)

# C++ includes.
MXCPP_CXX_INCLUDE := \
$(CXX_INCLUDE)$(MXCPP_INCLUDE_ROOT) \
$(CXX_INCLUDE)$(MXCPP_SRC_ROOT)inc


# Append platform includes.
$(foreach compiler,$(MXCPP_COMPILERS_LIST),\
	$(if $(strip $(MXCPP_$(compiler)_INCLUDE_PLATFORM)),\
		$(eval MXCPP_$(compiler)_INCLUDE += $(MXCPP_$(compiler)_INCLUDE_PLATFORM))))


# Configuration flags.
MXCPP_CFLAGS := $(CC_COMPILE_ONLY) $(CFLAGS) $(MXCPP_C_INCLUDE)
MXCPP_CXXFLAGS := $(CXX_COMPILE_ONLY) $(CXXFLAGS) $(MXCPP_CXX_INCLUDE)

MXCPP_LIBC_FLAGS := $(LIBC_FLAGS)
MXCPP_DLLC_FLAGS := $(DLLC_FLAGS)

# Append platform configuration flags.
$(foreach compiler,$(MXCPP_COMPILERS_LIST),\
	$(if $(strip $(MXCPP_$(compiler)FLAGS_PLATFORM)),\
		$(eval MXCPP_$(compiler)FLAGS += $(MXCPP_$(compiler)FLAGS_PLATFORM))))


# Makefile dependencies.
#
# Any change in the makefile initialization files *.ini, will cause full rebuild
# of all objects.
MXCPP_MAKEFILE_DEPS := $(filter %.ini,$(MAKEFILE_LIST))
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


# Run single build command.
#
# This is convenience macro for running build commands, to allow simple
# logging of commands.
#
# @param $(1) The build command, which would be processed.
#
define MXCPP_RUN_COMMAND
ifneq ($(strip $(MXCPP_COMMANDS_LOG)),)
	-@$(ECHO) $(1) >>$(MXCPP_COMMANDS_LOG)
endif
	$(2)@$(1) $(3)
endef	# MXCPP_RUN_COMMAND


# Construct build rules for building objects from source files.
#
# @param $(1) The source file name, relative to $(MXCPP_SRC_ROOT)
# @param $(2) The folder for destination object files.
# @param $(3) The build configuration list, separed by commas.
#
define MXCPP_BUILD_RULES_OBJECT

$(eval MXCPP_OBJECT_SUFFIX := $(suffix $(1)))

$(if $(strip $(findstring $(MXCPP_OBJECT_SUFFIX),.cpp .cxx .c++)),$(eval MXCPP_COMPILER_TYPE := CXX),\
$(if $(strip $(findstring $(MXCPP_OBJECT_SUFFIX),.c)),$(eval MXCPP_COMPILER_TYPE := CC),\
$(error ERROR: Unsupported source file type '$(suffix $(1))' (source file: $(1)))\
))

$(eval MXCPP_OBJECT := $(subst /,$(PATH_SEP),$(2)/$(basename $(notdir $(1)))).$(OBJ_SFX))

$(if $(strip $(MXCPP_MAKE_DEBUG)),$(warning SOURCE: $(MXCPP_SRC_ROOT)$(1)))
$(if $(strip $(MXCPP_MAKE_DEBUG)),$(warning OBJECT: $(MXCPP_OBJECT)))

$(if $(findstring $(MXCPP_OBJECT),$(MXCPP_OBJ_LIST)),$(error ERROR: Object ambiquity. Files listed in MXCPP_SRC_LIST must have different base names, to avoid object names ambiquity (source file: $(1))))

$(eval MXCPP_OBJ_LIST += $(MXCPP_OBJECT))

$(eval MXCPP_COMPILE_RULE := $$(call MXCPP_COMPILE_$(MXCPP_COMPILER_TYPE),$(MXCPP_SRC_ROOT)$(1),$(3)))

$(call MXCPP_BUILD_RULES_SINGLE_RULE,$(MXCPP_OBJECT),$$(MXCPP_MAKEFILE_DEPS) $$(MXCPP_SRC_ROOT)$(1),B)
	@$(ECHO) == $1 ...
$(call MXCPP_RUN_COMMAND,$(MXCPP_COMPILE_RULE))

endef	# MXCPP_BUILD_RULES_OBJECT


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

$(eval MXCPP_OBJ_LIST :=)
$(foreach srcfile,$(MXCPP_SRC_LIST),$(call MXCPP_BUILD_RULES_OBJECT,$(srcfile),$(MXCPP_OBJECT_DIR),$(1)$(MXCPP_COMMA)$(MXCPP_BUILD_RULES_CONFIGURATION_COMMA)))

$(if $(strip $(MXCPP_MAKE_DEBUG)),$(warning MXCPP_OBJ_LIST: $(MXCPP_OBJ_LIST)))


$(eval MXCPP_TARGET_SUBTYPE_MOD :=)
$(foreach subtype,$(2),$(eval MXCPP_TARGET_SUBTYPE_MOD += $(MXCPP_MOD_$(subtype))))
$(eval MXCPP_TARGET_SUBTYPE_MOD := $(subst $(MXCPP_EMPTY_SPACE),,$(MXCPP_TARGET_SUBTYPE_MOD)))

$(eval MXCPP_TARGET_LIBRARY := $(call MXCPP_$(1)_CONSTRUCT_NAME,$(MXCPP_TARGET_SUBTYPE_MOD)))
$(if $(strip $(MXCPP_MAKE_DEBUG)),$(warning MXCPP_TARGET_LIBRARY: "$(MXCPP_TARGET_LIBRARY)"))

$(eval MXCPP_BUILD_RULE := $$(call MXCPP_BUILD_$(MXCPP_LIBCONFIG_$(1)),$(MXCPP_OBJ_LIST),$(MXCPP_BUILD_RULES_CONFIGURATION_COMMA)))

$(call MXCPP_BUILD_RULES_SINGLE_RULE,_start_$(MXCPP_BUILD_RULES_SRC),,X)
	@$$(ECHO) Building $(MXCPP_BUILD_RULES_LIBRARY)($(MXCPP_BUILD_RULES_CONFIGURATION)) ...

$(call MXCPP_BUILD_RULES_SINGLE_RULE,$(MXCPP_BUILD_RULES_SRC),_start_$(MXCPP_BUILD_RULES_SRC) $(MXCPP_TARGET_LIBRARY),X)
	@$$(ECHO) ... building $(MXCPP_BUILD_RULES_LIBRARY)($(MXCPP_BUILD_RULES_CONFIGURATION)) done.

$(call MXCPP_BUILD_RULES_SINGLE_RULE,$(MXCPP_TARGET_LIBRARY),$(MXCPP_OBJECT_DIR) $(MXCPP_OBJ_LIST),A)
	@$$(ECHO) == linking ($$@) ...
$(call MXCPP_RUN_COMMAND,$(MXCPP_BUILD_RULE))

$(call MXCPP_BUILD_RULES_SINGLE_RULE,$(MXCPP_OBJECT_DIR),,X)
$(call MXCPP_RUN_COMMAND,$(MKDIR) $$@)

$(call MXCPP_BUILD_RULES_SINGLE_RULE,_start_test_$(MXCPP_BUILD_RULES_SRC),,X)
	@$$(ECHO) Testing $(MXCPP_BUILD_RULES_LIBRARY)($(MXCPP_BUILD_RULES_CONFIGURATION)) ...

$(call MXCPP_BUILD_RULES_SINGLE_RULE,test_$(MXCPP_BUILD_RULES_SRC) $(MXCPP_BUILD_RULES_SRC)_test,$(MXCPP_BUILD_RULES_SRC) _start_test_$(MXCPP_BUILD_RULES_SRC),X)
	@$$(ECHO) ... testing $(MXCPP_BUILD_RULES_LIBRARY)($(MXCPP_BUILD_RULES_CONFIGURATION)) done.

$(call MXCPP_BUILD_RULES_SINGLE_RULE,_start_clean_$(MXCPP_BUILD_RULES_SRC),,X)
	@$$(ECHO) Cleaning $(MXCPP_BUILD_RULES_LIBRARY)($(MXCPP_BUILD_RULES_CONFIGURATION)) ...

$(call MXCPP_BUILD_RULES_SINGLE_RULE,clean_$(MXCPP_BUILD_RULES_SRC),_start_clean_$(MXCPP_BUILD_RULES_SRC) _make_clean_$(MXCPP_BUILD_RULES_SRC),X)
	@$$(ECHO) ... cleaning $(MXCPP_BUILD_RULES_LIBRARY)($(MXCPP_BUILD_RULES_CONFIGURATION)) done.

$(call MXCPP_BUILD_RULES_SINGLE_RULE,_start_cleanall_$(MXCPP_BUILD_RULES_SRC),,X)
	@$$(ECHO) Cleaning all $(MXCPP_BUILD_RULES_LIBRARY)($(MXCPP_BUILD_RULES_CONFIGURATION)) ...

$(call MXCPP_BUILD_RULES_SINGLE_RULE,cleanall_$(MXCPP_BUILD_RULES_SRC),_start_cleanall_$(MXCPP_BUILD_RULES_SRC) _make_cleanall_$(MXCPP_BUILD_RULES_SRC),X)
	@$$(ECHO) ... cleaning all $(MXCPP_BUILD_RULES_LIBRARY)($(MXCPP_BUILD_RULES_CONFIGURATION)) done.

$(call MXCPP_BUILD_RULES_SINGLE_RULE,_make_clean_$(MXCPP_BUILD_RULES_SRC),,X)
$(call MXCPP_RUN_COMMAND,$(RM) $(MXCPP_OBJECT_DIR)$(PATH_SEP)*.$(OBJ_SFX),-,$(NOERROUT))
$(call MXCPP_RUN_COMMAND,$(RMDIR) $(MXCPP_OBJECT_DIR),-,$(NOERROUT))

$(call MXCPP_BUILD_RULES_SINGLE_RULE,_make_cleanall_$(MXCPP_BUILD_RULES_SRC),_make_clean_$(MXCPP_BUILD_RULES_SRC),X)
$(call MXCPP_RUN_COMMAND,$(RM) $(MXCPP_TARGET_LIBRARY),-,$(NOERROUT))

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
