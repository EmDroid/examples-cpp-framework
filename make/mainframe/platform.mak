##
# @file
#
# Makefile for the Demo C++ Framework project
#     - IBM Mainframe platform dependent options.
#
# @author Emil Maskovsky
#
# Does provide own set of build rules, global rules defined in global.mak are
# not used for the IBM mainframe platform.
#
# The rules are used to assemble the lists of files, which then will be used by
# the real build process on the mainframe machine.
#


# The default target.
all:


MXCPP_SCRIPT_COMMENT := TN3270 terminal script

MXCPP_AUTOGEN_COMMENT := This file is auto-generated, do not change it!


# Full build of the library.
all:	$(MXCPP_OBJLIB_LIST) $(MXCPP_TRANSFER_LIST)

# Run the tests.
test:	all


# Run directory initializer script.
init:	$(MXCPP_DIRINIT_LIST) setup
	cd setup && $(TERMINAL) $(CURDIR)/$(MXCPP_DIRINIT_LIST)


setup:
	md setup


# Clean intermediate targets.
clean:
	-@$(RM) $(MXCPP_OBJLIB_LIST) $(NOERROUT)
	-@$(RM) $(MXCPP_DSSETUP_SCRIPT) $(NOERROUT)
	-@$(RM) $(MXCPP_TRANSFER_LIST) $(NOERROUT)
	-@$(RM) $(MXCPP_DIRINIT_LIST) $(NOERROUT)

# Clean all targets.
# (currently the same as the 'clean' target)
cleanall:	clean


define MXCPP_AUTOGEN_HEADER
	$(ECHO) * $(1)>$@
	$(ECHO) * $(MXCPP_SCRIPT_COMMENT)>>$@
	$(ECHO).>>$@
	$(ECHO) * $(MXCPP_AUTOGEN_COMMENT)>>$@
	$(ECHO).>>$@

endef	# MXCPP_AUTOGEN_HEADER

define MXCPP_AUTOGEN_FOOTER
	@$(ECHO).>>$@
	@$(ECHO) * EOF>>$@

endef	# MXCPP_AUTOGEN_FOOTER


define MXCPP_RULE_OBJLIB
	$(ECHO)   INCLUDE $(MXCPP_NAME_OBJLIB)($(basename $(notdir $(firstword $(1)))))$(2)

endef	# MXCPP_RULE_OBJLIB

$(MXCPP_OBJLIB_LIST):	../../global.ini ../platform.mak
	@$(ECHO) - building the object library list ...
	@$(call MXCPP_RULE_OBJLIB,$(firstword $(MXCPP_SRC_LIST)),>$(MXCPP_OBJLIB_LIST))
	@$(foreach source,$(wordlist 2,$(words $(MXCPP_SRC_LIST)),$(MXCPP_SRC_LIST)),$(call MXCPP_RULE_OBJLIB,$(source),>>$(MXCPP_OBJLIB_LIST)))
	@$(ECHO)   ... the object library list done.


define MXCPP_RULE_TRANSFER
	$(ECHO).>>$@
	$(ECHO) SetVar $$PCNAME,$$$(2),"$(1)">>$@
	$(ECHO) SetVar $$HOSTNAME,$$$(3),".$(subst /,.,$(subst ./,,$(dir $(1))))",$$$(4),"($(basename $(notdir $(1))))">>$@
	$(ECHO) FileTransfer operation=send,>>$@
	$(ECHO)         pcfile=$$PCNAME,>>$@
	$(ECHO)         hostfile=$$HOSTNAME,>>$@
	$(ECHO)         opsys=mvs/tso, Recfm=default,>>$@
	$(ECHO)         options="ascii crlf">>$@

endef	# MXCPP_RULE_TRANSFER

MXCPP_SRC_LIST_FILTERED := $(filter-out $(MXCPP_SRC_LIST_SINGLE) $(MXCPP_SRC_LIST_INTERNAL),$(MXCPP_SRC_LIST))

# The file transfer list.
# (dependent of source files list set in)
$(MXCPP_TRANSFER_LIST):	../../global.ini ../platform.ini ../platform.mak $(MXCPP_DSSETUP_SCRIPT)
	@$(ECHO) - assembling the file transfer list ...
	@$(call MXCPP_AUTOGEN_HEADER,Transfer the files to mainframe)
	@$(ECHO) * Connect to mainframe>>$@
	@$(ECHO) include $(CURDIR)/$(MXCPP_LOGIN_SCRIPT)>>$@
	@$(ECHO) include $(CURDIR)/Connect.$(MXCPP_FINALSCR_SUFF)>>$@
	@$(ECHO) include $(CURDIR)/$(MXCPP_DSSETUP_SCRIPT)>>$@
	@$(foreach header,$(MXCPP_EXTRA_INCLUDE) $(MXCPP_SRC_LIST_FILTERED:.cpp=.hpp),$(call MXCPP_RULE_TRANSFER,$(MXCPP_CONFIG_SUFFIX)/$(header),$(MXCPP_NAME_INCLUDE_DIR),$(MXCPP_NAME_TARGET_DIR),$(MXCPP_NAME_HOST_HPP)))
	@$(foreach header,$(MXCPP_SRC_LIST_INTERNAL:.cpp=.hpp),$(call MXCPP_RULE_TRANSFER,$(MXCPP_CONFIG_SUFFIX)/internal/$(header),$(MXCPP_NAME_INTERNAL_INCLUDE_DIR),$(MXCPP_NAME_TARGET_DIR),$(MXCPP_NAME_HOST_HPP)))
	@$(foreach header,$(MXCPP_SRC_LIST_FILTERED:.cpp=.inl),$(call MXCPP_RULE_TRANSFER,$(MXCPP_CONFIG_SUFFIX)/$(header),$(MXCPP_NAME_INCLUDE_DIR),$(MXCPP_NAME_TARGET_DIR),$(MXCPP_NAME_HOST_INL)))
	@$(foreach header,$(MXCPP_SRC_LIST_INTERNAL:.cpp=.inl),$(call MXCPP_RULE_TRANSFER,$(MXCPP_CONFIG_SUFFIX)/internal/$(header),$(MXCPP_NAME_INTERNAL_INCLUDE_DIR),$(MXCPP_NAME_TARGET_DIR),$(MXCPP_NAME_HOST_INL)))
	@$(foreach source,$(MXCPP_SRC_LIST),$(call MXCPP_RULE_TRANSFER,$(source),$(MXCPP_NAME_SOURCE_DIR),$(MXCPP_NAME_TARGET_DIR),$(MXCPP_NAME_HOST_CPP)))
	@$(foreach source,$(MXCPP_TEST_LIST),$(call MXCPP_RULE_TRANSFER,$(source),$(MXCPP_NAME_TEST_DIR),$(MXCPP_NAME_TARGET_DIR),$(MXCPP_NAME_HOST_TEST)))
	@$(foreach job,$(MXCPP_JOBS_LIST),$(call MXCPP_RULE_TRANSFER,$(job),$(MXCPP_NAME_JOBS_DIR),$(MXCPP_NAME_TARGET_DIR),$(MXCPP_NAME_HOST_JOBS)))
	@$(call MXCPP_AUTOGEN_FOOTER)
	@$(ECHO)   ... the file transfer list done.


$(MXCPP_DSSETUP_SCRIPT):	../../global.ini ../platform.ini ../platform.mak
	@$(ECHO) - assembling the DataSet setup script ...
	@$(call MXCPP_AUTOGEN_HEADER,Setup the datasets)
	@$(ECHO) global $$$(MXCPP_NAME_ROOT_DIR),$$$(MXCPP_NAME_INCLUDE_DIR),$$$(MXCPP_NAME_SOURCE_DIR),$$$(MXCPP_NAME_INTERNAL_INCLUDE_DIR),$$$(MXCPP_NAME_TEST_DIR),$$$(MXCPP_NAME_JOBS_DIR),$$$(MXCPP_NAME_TARGET_DIR),$$$(MXCPP_NAME_HOST_HPP),$$$(MXCPP_NAME_HOST_INL),$$$(MXCPP_NAME_HOST_CPP),$$$(MXCPP_NAME_HOST_TEST),$$$(MXCPP_NAME_HOST_JOBS)>>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_ROOT_DIR),"$(MXCPP_PROJECT_ROOT)">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_INCLUDE_DIR),$$$(MXCPP_NAME_ROOT_DIR),"$(MXCPP_INCLUDE_NAME)/">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_SOURCE_DIR),$$$(MXCPP_NAME_ROOT_DIR),"$(MXCPP_SRC_NAME)">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_INTERNAL_INCLUDE_DIR),$$$(MXCPP_NAME_SOURCE_DIR),"$(MXCPP_INCLUDE_NAME)/">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_TEST_DIR),$$$(MXCPP_NAME_SOURCE_DIR),"$(MXCPP_TEST_NAME)">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_JOBS_DIR),"">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_TARGET_DIR),"$(MXCPP_NAME_TARGET_DIR_VALUE)">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_HOST_HPP),"$(MXCPP_NAME_HOST_HPP_VALUE)">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_HOST_INL),"$(MXCPP_NAME_HOST_INL_VALUE)">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_HOST_CPP),"$(MXCPP_NAME_HOST_CPP_VALUE)">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_HOST_TEST),"$(MXCPP_NAME_HOST_TEST_VALUE)">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_HOST_JOBS),"$(MXCPP_NAME_HOST_JOBS_VALUE)">>$@
	@$(call MXCPP_AUTOGEN_FOOTER)
	@$(ECHO)   ... the DataSet setup script done.


MXCPP_DIRS_LIST :=

define MXCPP_BUILD_DIRLIST
$(eval MXCPP_DIR := .$(subst /,.,$(subst ./,,$(dir $(1)))))
$(if $(strip $(findstring $(MXCPP_DIR),$(MXCPP_DIRS_LIST))),,$(eval MXCPP_DIRS_LIST += $(MXCPP_DIR)))
endef	# MXCPP_BUILD_DIRLIST

$(foreach source,$(MXCPP_SRC_LIST),$(eval $(call MXCPP_BUILD_DIRLIST,$(source))))

MXCPP_DIR := $(MXCPP_DIRS_LIST)

MXCPP_DIRS_LIST :=
$(foreach dir,$(MXCPP_DIR),$(eval MXCPP_DIRS_LIST += $$$$$(MXCPP_NAME_TARGET_DIR),".$(MXCPP_CONFIG_SUFFIX)$(dir)",$$$$$(MXCPP_NAME_HOST_HPP) $$$$$(MXCPP_NAME_TARGET_DIR),".$(MXCPP_CONFIG_SUFFIX)$(dir)",$$$$$(MXCPP_NAME_HOST_INL) $$$$$(MXCPP_NAME_TARGET_DIR),"$(dir)",$$$$$(MXCPP_NAME_HOST_CPP)))
MXCPP_DIRS_LIST += \
$$$(MXCPP_NAME_TARGET_DIR),".$(MXCPP_CONFIG_SUFFIX).internal.",$$$(MXCPP_NAME_HOST_HPP)	\
$$$(MXCPP_NAME_TARGET_DIR),".$(MXCPP_CONFIG_SUFFIX).internal.",$$$(MXCPP_NAME_HOST_INL)	\
$$$(MXCPP_NAME_TARGET_DIR),".",$$$(MXCPP_NAME_HOST_TEST)	\
$$$(MXCPP_NAME_TARGET_DIR),".",$$$(MXCPP_NAME_HOST_JOBS)

define MXCPP_RULE_DIRLIST
	$(ECHO).>>$@
	$(ECHO) SetVar $$DIRNAME,$(1)>>$@
	$(ECHO) type $$DIRNAME>>$@
	$(ECHO) key Enter>>$@

endef	# MXCPP_RULE_DIRLIST

# The directory initializer list.
$(MXCPP_DIRINIT_LIST):	../../global.ini ../platform.mak $(MXCPP_LOGIN_SCRIPT) $(MXCPP_DSSETUP_SCRIPT)
	@$(ECHO) - assembling the directory init script ...
	@$(call MXCPP_AUTOGEN_HEADER,Initialize directories on mainframe)
	@$(ECHO) * Connect to mainframe>>$@
	@$(ECHO) include $(CURDIR)/$(MXCPP_LOGIN_SCRIPT)>>$@
	@$(ECHO) include $(CURDIR)/Connect.$(MXCPP_FINALSCR_SUFF)>>$@
	@$(ECHO) include $(CURDIR)/$(MXCPP_DSSETUP_SCRIPT)>>$@
	@$(foreach dir,$(MXCPP_DIRS_LIST),$(call MXCPP_RULE_DIRLIST,$(dir)))
	@$(call MXCPP_AUTOGEN_FOOTER)
	@$(ECHO)   ... the directory init script done.


# The login script.
$(MXCPP_LOGIN_SCRIPT):
	@$(ECHO) - assembling the login script ...
	@$(ECHO) * The login script>$@
	@$(ECHO) * $(MXCPP_SCRIPT_COMMENT)>>$@
	@$(ECHO).>>$@
	@$(ECHO) * Adapt this login script to your environment.>>$@
	@$(ECHO).>>$@
	@$(ECHO) global $$HOSTSESSION,$$HOSTLOGIN,$$HOSTPASSWORD>>$@
	@$(ECHO).>>$@
	@$(ECHO) * The TSO session name>>$@
	@$(ECHO) SetVar $$HOSTSESSION,TheHostSessionName>>$@
	@$(ECHO).>>$@
	@$(ECHO) * The session login name>>$@
	@$(ECHO) SetVar $$HOSTLOGIN,MyLoginName>>$@
	@$(ECHO) * The session login password (warning: storing the password is unsafe)>>$@
	@$(ECHO) SetVar $$HOSTPASSWORD,*****>>$@
	@$(call MXCPP_AUTOGEN_FOOTER)
ifneq ($(strip $(EDITOR)),)
	-@$(EDITOR) $(MXCPP_LOGIN_SCRIPT)
endif
	@$(ECHO)   ... the login script done.


# EOF #
