
# The default target.
release:


# Uncomment following line, if you wisch to debug the build make system.
# The MXCPP_MAKE_DEBUG can also be set on the make command line.
#MXCPP_MAKE_DEBUG := 1

# Allow the value '0' for disabling the debug.
# 'override' directive for working even for make command line.
override MXCPP_MAKE_DEBUG := $(filter-out 0,$(MXCPP_MAKE_DEBUG))

# Logging targets (for debug purposes).
# May also be set on the make command line.
# MXCPP_TARGETS_LOG := targets.log
$(if $(strip $(MXCPP_MAKE_DEBUG)),$(eval MXCPP_TARGETS_LOG := targets.log))

$(if $(strip $(MXCPP_TARGETS_LOG)),$(shell $(RM) $(MXCPP_TARGETS_LOG)))


define MXCPP_BUILD_RULES_SINGLE_RULE

$(if $(strip $(MXCPP_TARGETS_LOG)),$(shell $(ECHO) ($(3)) $(1): $(2) >> $(MXCPP_TARGETS_LOG)))

$(1): $(2)

endef	# MXCPP_BUILD_RULES_SINGLE_RULE


# Main targets.
$(call MXCPP_BUILD_RULES_SINGLE_RULE,all,,.)

$(call MXCPP_BUILD_RULES_SINGLE_RULE,test testall test_all,all,.)


MXCPP_EMPTY_SPACE :=
MXCPP_EMPTY_SPACE := $(MXCPP_EMPTY_SPACE) $(MXCPP_EMPTY_SPACE)

define MXCPP_BUILD_RULES_GROUP

$(eval MXCPP_BUILD_RULES_SRC := $(subst $(MXCPP_EMPTY_SPACE),$(3),$(strip $(1))))
$(eval MXCPP_BUILD_RULES_TGT := $(subst $(MXCPP_EMPTY_SPACE),$(3),$(strip $(2))))

$(call MXCPP_BUILD_RULES_SINGLE_RULE,$(if $(strip $(MXCPP_BUILD_RULES_SRC)),$(MXCPP_BUILD_RULES_SRC),all),$(MXCPP_BUILD_RULES_TGT),$(4))

$(call MXCPP_BUILD_RULES_SINGLE_RULE,$(if $(strip $(MXCPP_BUILD_RULES_SRC)),test$(3)$(MXCPP_BUILD_RULES_SRC) $(MXCPP_BUILD_RULES_SRC)$(3)test,test),test_$(MXCPP_BUILD_RULES_TGT),$(4))
$(if $(strip $(3)),,$(call MXCPP_BUILD_RULES_SINGLE_RULE,test_$(MXCPP_BUILD_RULES_SRC) $(MXCPP_BUILD_RULES_SRC)_test,test_$(MXCPP_BUILD_RULES_TGT),$(4)))

$(foreach cleantype,clean cleanall,$(call MXCPP_BUILD_RULES_SINGLE_RULE,$(if $(strip $(MXCPP_BUILD_RULES_SRC)),$(cleantype)_$(MXCPP_BUILD_RULES_SRC),$(cleantype)),$(cleantype)_$(MXCPP_BUILD_RULES_TGT),$(4)))

endef	# MXCPP_BUILD_RULES_GROUP


define MXCPP_BUILD_RULES_OBJECT

$(if $(strip $(findstring $(suffix $(1)),.c .cpp)),,$(error ERROR: Unsupported source file type '$(suffix $(1))' (source file: $(1))))

$(eval MXCPP_OBJECT := $(2)/$(basename $(notdir $(1))).$(OBJ_SFX))

$(if $(strip $(MXCPP_MAKE_DEBUG)),$(warning SOURCE: $(1)))
$(if $(strip $(MXCPP_MAKE_DEBUG)),$(warning OBJECT: $(MXCPP_OBJECT)))

$(if $(findstring $(MXCPP_OBJECT),$(MXCPP_OBJ_LIST)),$(error ERROR: Object ambiquity. Files listed in MXCPP_SRC_LIST must have different base names, to avoid object names ambiquity (source file: $(1))))

$(eval MXCPP_OBJ_LIST += $(MXCPP_OBJECT))

$(call MXCPP_BUILD_RULES_SINGLE_RULE,$(MXCPP_OBJECT),$(1),B)
	@$(ECHO)     --- compiling $$@ ...

endef	# MXCPP_BUILD_RULES_OBJECT


define MXCPP_BUILD_RULES_FINAL

$(eval MXCPP_BUILD_RULES_LIBRARY := $(strip $(1)))
$(eval MXCPP_BUILD_RULES_CONFIGURATION := $(strip $(2)))
$(eval MXCPP_BUILD_RULES_SRC := $(subst $(MXCPP_EMPTY_SPACE),_,$(MXCPP_BUILD_RULES_LIBRARY) $(MXCPP_BUILD_RULES_CONFIGURATION)))

$(eval MXCPP_BUILD_RULES_CONFIGURATION := $(subst $(MXCPP_EMPTY_SPACE),-,$(MXCPP_BUILD_RULES_CONFIGURATION)))


$(eval MXCPP_OBJECT_DIR := obj)
$(foreach modifier,$(2),$(eval MXCPP_OBJECT_DIR += $(MXCPP_MOD_$(modifier))))
$(eval MXCPP_OBJECT_DIR += $(MXCPP_MOD_$(MXCPP_BUILD_RULES_LIBRARY)))
$(eval MXCPP_OBJECT_DIR := $(subst $(MXCPP_EMPTY_SPACE),,$(MXCPP_OBJECT_DIR)))

$(eval MXCPP_OBJ_LIST :=)
$(foreach srcfile,$(MXCPP_SRC_LIST),$(call MXCPP_BUILD_RULES_OBJECT,$(srcfile),$(MXCPP_OBJECT_DIR)))

$(if $(strip $(MXCPP_MAKE_DEBUG)),$(warning MXCPP_OBJ_LIST: $(MXCPP_OBJ_LIST)))


$(eval MXCPP_TARGET_SUBTYPE_MOD :=)
$(foreach subtype,$(2),$(eval MXCPP_TARGET_SUBTYPE_MOD += $(MXCPP_MOD_$(subtype))))
$(eval MXCPP_TARGET_SUBTYPE_MOD := $(subst $(MXCPP_EMPTY_SPACE),,$(MXCPP_TARGET_SUBTYPE_MOD)))

$(eval MXCPP_TARGET_LIBRARY := $(call MXCPP_$(1)_CONSTRUCT_NAME,$(MXCPP_TARGET_SUBTYPE_MOD)))
$(if $(strip $(MXCPP_MAKE_DEBUG)),$(warning MXCPP_TARGET_LIBRARY: "$(MXCPP_TARGET_LIBRARY)"))


$(call MXCPP_BUILD_RULES_SINGLE_RULE,_start_$(MXCPP_BUILD_RULES_SRC),,X)
	@$(ECHO) Building $(MXCPP_BUILD_RULES_LIBRARY)($(MXCPP_BUILD_RULES_CONFIGURATION)) ...

$(call MXCPP_BUILD_RULES_SINGLE_RULE,$(MXCPP_BUILD_RULES_SRC),_start_$(MXCPP_BUILD_RULES_SRC) $(MXCPP_TARGET_LIBRARY),X)
	@$(ECHO) ... building $(MXCPP_BUILD_RULES_LIBRARY)($(MXCPP_BUILD_RULES_CONFIGURATION)) done.

$(call MXCPP_BUILD_RULES_SINGLE_RULE,$(MXCPP_TARGET_LIBRARY),$(MXCPP_OBJ_LIST),A)
	@$(ECHO) * Building $$@ ...

$(call MXCPP_BUILD_RULES_SINGLE_RULE,_start_test_$(MXCPP_BUILD_RULES_SRC),,X)
	@$(ECHO) Testing $(MXCPP_BUILD_RULES_LIBRARY)($(MXCPP_BUILD_RULES_CONFIGURATION)) ...

$(call MXCPP_BUILD_RULES_SINGLE_RULE,test_$(MXCPP_BUILD_RULES_SRC) $(MXCPP_BUILD_RULES_SRC)_test,$(MXCPP_BUILD_RULES_SRC) _start_test_$(MXCPP_BUILD_RULES_SRC),X)
	@$(ECHO) ... testing $(MXCPP_BUILD_RULES_LIBRARY)($(MXCPP_BUILD_RULES_CONFIGURATION)) done.

$(call MXCPP_BUILD_RULES_SINGLE_RULE,_start_clean_$(MXCPP_BUILD_RULES_SRC),,X)
	@$(ECHO) Cleaning $(MXCPP_BUILD_RULES_LIBRARY)($(MXCPP_BUILD_RULES_CONFIGURATION)) ...

$(call MXCPP_BUILD_RULES_SINGLE_RULE,clean_$(MXCPP_BUILD_RULES_SRC),_start_clean_$(MXCPP_BUILD_RULES_SRC) _make_clean_$(MXCPP_BUILD_RULES_SRC),X)
	@$(ECHO) ... cleaning $(MXCPP_BUILD_RULES_LIBRARY)($(MXCPP_BUILD_RULES_CONFIGURATION)) done.

$(call MXCPP_BUILD_RULES_SINGLE_RULE,_start_cleanall_$(MXCPP_BUILD_RULES_SRC),,X)
	@$(ECHO) Cleaning all $(MXCPP_BUILD_RULES_LIBRARY)($(MXCPP_BUILD_RULES_CONFIGURATION)) ...

$(call MXCPP_BUILD_RULES_SINGLE_RULE,cleanall_$(MXCPP_BUILD_RULES_SRC),_start_cleanall_$(MXCPP_BUILD_RULES_SRC) _make_cleanall_$(MXCPP_BUILD_RULES_SRC),X)
	@$(ECHO) ... cleaning all $(MXCPP_BUILD_RULES_LIBRARY)($(MXCPP_BUILD_RULES_CONFIGURATION)) done.

$(call MXCPP_BUILD_RULES_SINGLE_RULE,_make_clean_$(MXCPP_BUILD_RULES_SRC),,X)
	@$(ECHO) = objects cleanup

$(call MXCPP_BUILD_RULES_SINGLE_RULE,_make_cleanall_$(MXCPP_BUILD_RULES_SRC),_make_clean_$(MXCPP_BUILD_RULES_SRC),X)
	@$(ECHO) = final cleanup

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
