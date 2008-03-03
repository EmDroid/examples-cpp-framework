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


# Main build dependencies.
_buildall_deps:	$(MXCPP_LOGIN_SCRIPT) $(MXCPP_CONNECT_SCRIPT) $(MXCPP_JOBS_LIST) $(MXCPP_TRANSFER_LIST) $(MXCPP_BUILD_SCRIPT) $(MXCPP_BUILD_RUN_SCRIPT)

# Full build of the library.
all:	_buildall_deps setup
	cd setup && $(TERMINAL) $(CURDIR)/$(MXCPP_BUILD_RUN_SCRIPT)

# Run the tests.
test:	_buildall_deps $(MXCPP_TEST_JOBS_LIST) $(MXCPP_TEST_TRANSFER_LIST) $(MXCPP_TEST_BUILD_SCRIPT) $(MXCPP_TEST_BUILD_RUN_SCRIPT) setup
	cd setup && $(TERMINAL) $(CURDIR)/$(MXCPP_TEST_BUILD_RUN_SCRIPT)

# Run directory initializer script.
init:	$(MXCPP_LOGIN_SCRIPT) $(MXCPP_CONNECT_SCRIPT) $(MXCPP_DIRINIT_LIST) $(MXCPP_DIRINIT_SCRIPT) setup
	cd setup && $(TERMINAL) $(CURDIR)/$(MXCPP_DIRINIT_SCRIPT)


setup:
	md setup


# Clean intermediate targets.
clean:
	-@$(RM) $(MXCPP_DIRINIT_SCRIPT) $(NOERROUT)
	-@$(RM) $(MXCPP_DIRINIT_LIST) $(NOERROUT)
	-@$(RM) $(MXCPP_TEST_BUILD_RUN_SCRIPT) $(NOERROUT)
	-@$(RM) $(MXCPP_TEST_BUILD_SCRIPT) $(NOERROUT)
	-@$(RM) $(MXCPP_TEST_TRANSFER_LIST) $(NOERROUT)
	-@$(RM) $(MXCPP_BUILD_RUN_SCRIPT) $(NOERROUT)
	-@$(RM) $(MXCPP_BUILD_SCRIPT) $(NOERROUT)
	-@$(RM) $(MXCPP_TRANSFER_LIST) $(NOERROUT)
	-@$(RM) $(MXCPP_OBJLIB_LIST) $(NOERROUT)
	-@$(RM) $(MXCPP_DSSETUP_SCRIPT) $(NOERROUT)

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
	$(ECHO) include $(CURDIR)/FileTrans.$(MXCPP_FINALSCR_SUFF)>>$@

endef	# MXCPP_RULE_TRANSFER

MXCPP_SRC_LIST_FILTERED := $(filter-out $(MXCPP_SRC_LIST_SINGLE) $(MXCPP_SRC_LIST_INTERNAL),$(MXCPP_SRC_LIST))

# Transfer the library files.
$(MXCPP_TRANSFER_LIST):	$(MXCPP_DSSETUP_SCRIPT)
	@$(ECHO) - assembling the library file transfer list ...
	@$(call MXCPP_AUTOGEN_HEADER,Transfer the library files to mainframe)
	@$(ECHO).>>$@
	@$(ECHO) * Setup the script>>$@
	@$(ECHO) include $(CURDIR)/$(MXCPP_DSSETUP_SCRIPT)>>$@
	@$(ECHO).>>$@
	@$(ECHO) global $$PCNAME,$$HOSTNAME>>$@
	@$(ECHO).>>$@
	@$(ECHO).>>$@
	@$(ECHO) * Initialize the file transfer>>$@
	@$(ECHO) include $(CURDIR)/Transfer.$(MXCPP_FINALSCR_SUFF)>>$@
	@$(ECHO).>>$@
	@$(ECHO).>>$@
	@$(ECHO) * Library header files>>$@
	@$(foreach header,$(MXCPP_EXTRA_INCLUDE) $(MXCPP_SRC_LIST_FILTERED:.cpp=.hpp),$(call MXCPP_RULE_TRANSFER,$(MXCPP_CONFIG_SUFFIX)/$(header),$(MXCPP_NAME_INCLUDE_DIR),$(MXCPP_NAME_TARGET_DIR),$(MXCPP_NAME_HOST_HPP)))
	@$(foreach header,$(MXCPP_SRC_LIST_FILTERED:.cpp=.inl),$(call MXCPP_RULE_TRANSFER,$(MXCPP_CONFIG_SUFFIX)/$(header),$(MXCPP_NAME_INCLUDE_DIR),$(MXCPP_NAME_TARGET_DIR),$(MXCPP_NAME_HOST_INL)))
	@$(ECHO).>>$@
	@$(ECHO).>>$@
	@$(ECHO) * Library internal header files>>$@
	@$(foreach header,$(MXCPP_SRC_LIST_INTERNAL:.cpp=.hpp),$(call MXCPP_RULE_TRANSFER,$(MXCPP_CONFIG_SUFFIX)/internal/$(header),$(MXCPP_NAME_INTERNAL_INCLUDE_DIR),$(MXCPP_NAME_TARGET_DIR),$(MXCPP_NAME_HOST_HPP)))
	@$(foreach header,$(MXCPP_SRC_LIST_INTERNAL:.cpp=.inl),$(call MXCPP_RULE_TRANSFER,$(MXCPP_CONFIG_SUFFIX)/internal/$(header),$(MXCPP_NAME_INTERNAL_INCLUDE_DIR),$(MXCPP_NAME_TARGET_DIR),$(MXCPP_NAME_HOST_INL)))
	@$(ECHO).>>$@
	@$(ECHO).>>$@
	@$(ECHO) * Library source files>>$@
	@$(foreach source,$(MXCPP_SRC_LIST),$(call MXCPP_RULE_TRANSFER,$(source),$(MXCPP_NAME_SOURCE_DIR),$(MXCPP_NAME_TARGET_DIR),$(MXCPP_NAME_HOST_CPP)))
	@$(ECHO).>>$@
	@$(ECHO).>>$@
	@$(ECHO) * Jobs>>$@
	@$(foreach job,$(MXCPP_JOBS_LIST),$(call MXCPP_RULE_TRANSFER,$(job),$(MXCPP_NAME_JOBS_DIR),$(MXCPP_NAME_TARGET_DIR),$(MXCPP_NAME_HOST_JOBS)))
	@$(ECHO).>>$@
	@$(ECHO).>>$@
	@$(ECHO) * Return from the ISPF Command Shell>>$@
	@$(ECHO) Key PF3>>$@
	@$(call MXCPP_AUTOGEN_FOOTER)
	@$(ECHO)   ... the library file transfer list done.

# Transfer the library tests files.
$(MXCPP_TEST_TRANSFER_LIST):	$(MXCPP_DSSETUP_SCRIPT)
	@$(ECHO) - assembling the library tests file transfer list ...
	@$(call MXCPP_AUTOGEN_HEADER,Transfer the library tests files to mainframe)
	@$(ECHO).>>$@
	@$(ECHO) * Transfer the library files>>$@
	@$(ECHO) include $(CURDIR)/$(MXCPP_TRANSFER_LIST)>>$@
	@$(ECHO).>>$@
	@$(ECHO).>>$@
	@$(ECHO) * Initialize the file transfer again>>$@
	@$(ECHO) include $(CURDIR)/Transfer.$(MXCPP_FINALSCR_SUFF)>>$@
	@$(ECHO).>>$@
	@$(ECHO).>>$@
	@$(ECHO) * Library tests>>$@
	@$(foreach source,$(MXCPP_TEST_LIST),$(call MXCPP_RULE_TRANSFER,$(source),$(MXCPP_NAME_TEST_DIR),$(MXCPP_NAME_TARGET_DIR),$(MXCPP_NAME_HOST_TEST)))
	@$(ECHO).>>$@
	@$(ECHO).>>$@
	@$(ECHO) * Library test jobs>>$@
	@$(foreach job,$(MXCPP_TEST_JOBS_LIST),$(call MXCPP_RULE_TRANSFER,$(job),$(MXCPP_NAME_JOBS_DIR),$(MXCPP_NAME_TARGET_DIR),$(MXCPP_NAME_HOST_JOBS)))
	@$(ECHO).>>$@
	@$(ECHO).>>$@
	@$(ECHO) * Return from the ISPF Command Shell>>$@
	@$(ECHO) Key PF3>>$@
	@$(call MXCPP_AUTOGEN_FOOTER)
	@$(ECHO)   ... the library tests file transfer list done.


# The library build script.
$(MXCPP_BUILD_SCRIPT):	../platform.ini
	@$(ECHO) - assembling the library build script ...
	@$(call MXCPP_AUTOGEN_HEADER,Build the library on mainframe)
	@$(ECHO) * Transfer the library files>>$@
	@$(ECHO) include $(CURDIR)/$(MXCPP_TRANSFER_LIST)>>$@
	@$(ECHO).>>$@
	@$(ECHO) * Start the library build>>$@
	@$(ECHO) global $$JOBNAME>>$@
	@$(ECHO) SetVar $$JOBNAME,$$$(MXCPP_NAME_TARGET_DIR),".",$$$(MXCPP_NAME_HOST_JOBS),"($(MXCPP_BUILD_JOB))">>$@
	@$(ECHO) include $(CURDIR)/RunJob.$(MXCPP_FINALSCR_SUFF)>>$@
	@$(call MXCPP_AUTOGEN_FOOTER)
	@$(ECHO)   ... the library build script done.

# The library tests build and run script.
$(MXCPP_TEST_BUILD_SCRIPT):	../platform.ini
	@$(ECHO) - assembling the library tests build script ...
	@$(call MXCPP_AUTOGEN_HEADER,Build and run the library tests on mainframe)
	@$(ECHO) * Transfer the library tests files>>$@
	@$(ECHO) include $(CURDIR)/$(MXCPP_TEST_TRANSFER_LIST)>>$@
	@$(ECHO).>>$@
	@$(ECHO) * Start the library build>>$@
	@$(ECHO).>>$@
	@$(ECHO) * Start the library tests build>>$@
	@$(ECHO) global $$JOBNAME>>$@
	@$(ECHO) SetVar $$JOBNAME,$$$(MXCPP_NAME_TARGET_DIR),".",$$$(MXCPP_NAME_HOST_JOBS),"($(MXCPP_TEST_BUILD_JOB))">>$@
	@$(ECHO) include $(CURDIR)/RunJob.$(MXCPP_FINALSCR_SUFF)>>$@
	@$(call MXCPP_AUTOGEN_FOOTER)
	@$(ECHO)   ... the library tests build script done.


define MXCPP_RULE_CONNECT
	$(ECHO) * Connect to mainframe>>$@
	$(ECHO) include $(CURDIR)/$(MXCPP_LOGIN_SCRIPT)>>$@
	$(ECHO) global $$CONNECT_SETUP>>$@
	$(ECHO) SetVar $$CONNECT_SETUP,$(CURDIR)/$(MXCPP_CONNECT_SCRIPT)>>$@
	$(ECHO) include $(CURDIR)/Connect.$(MXCPP_FINALSCR_SUFF)>>$@
	$(ECHO).>>$@

endef	# MXCPP_RULE_CONNECT

# The library build script with connecting.
$(MXCPP_BUILD_RUN_SCRIPT):	../platform.ini
	@$(ECHO) - assembling the library full build script ...
	@$(call MXCPP_AUTOGEN_HEADER,Build the library on mainframe - full run with logging on)
	@$(call MXCPP_RULE_CONNECT)
	@$(ECHO) * Run the library build script>>$@
	@$(ECHO) include $(CURDIR)/$(MXCPP_BUILD_SCRIPT)>>$@
	@$(call MXCPP_AUTOGEN_FOOTER)
	@$(ECHO)   ... the library full build script done.

# The library tests build and run script with connecting.
$(MXCPP_TEST_BUILD_RUN_SCRIPT):	../platform.ini
	@$(ECHO) - assembling the library tests full build script ...
	@$(call MXCPP_AUTOGEN_HEADER,Build and run the library tests on mainframe - full run with logging on)
	@$(call MXCPP_RULE_CONNECT)
	@$(ECHO) * Run the library tests build script>>$@
	@$(ECHO) include $(CURDIR)/$(MXCPP_TEST_BUILD_SCRIPT)>>$@
	@$(call MXCPP_AUTOGEN_FOOTER)
	@$(ECHO)   ... the library tests full build script done.


$(MXCPP_DSSETUP_SCRIPT):	../../global.ini ../platform.ini ../platform.mak
	@$(ECHO) - assembling the DataSet setup script ...
	@$(call MXCPP_AUTOGEN_HEADER,Setup the datasets)
	@$(ECHO) global $$$(MXCPP_NAME_INCLUDE_DIR),$$$(MXCPP_NAME_SOURCE_DIR),$$$(MXCPP_NAME_INTERNAL_INCLUDE_DIR),$$$(MXCPP_NAME_TEST_DIR),$$$(MXCPP_NAME_JOBS_DIR),$$$(MXCPP_NAME_TARGET_DIR),$$$(MXCPP_NAME_HOST_HPP),$$$(MXCPP_NAME_HOST_INL),$$$(MXCPP_NAME_HOST_CPP),$$$(MXCPP_NAME_HOST_TEST),$$$(MXCPP_NAME_HOST_JOBS)>>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_CURRENT_DIR),"$(CURDIR)/">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_ROOT_DIR),$$$(MXCPP_NAME_CURRENT_DIR),"$(MXCPP_PROJECT_ROOT)">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_INCLUDE_DIR),$$$(MXCPP_NAME_ROOT_DIR),"$(MXCPP_INCLUDE_NAME)/">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_SOURCE_DIR),$$$(MXCPP_NAME_ROOT_DIR),"$(MXCPP_SRC_NAME)">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_INTERNAL_INCLUDE_DIR),$$$(MXCPP_NAME_SOURCE_DIR),"$(MXCPP_INCLUDE_NAME)/">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_TEST_DIR),$$$(MXCPP_NAME_SOURCE_DIR),"$(MXCPP_TEST_NAME)">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_JOBS_DIR),$$$(MXCPP_NAME_CURRENT_DIR)>>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_TARGET_DIR),"$(MXCPP_NAME_TARGET_DIR_VALUE)">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_HOST_HPP),"$(MXCPP_NAME_HOST_HPP_VALUE)">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_HOST_INL),"$(MXCPP_NAME_HOST_INL_VALUE)">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_HOST_CPP),"$(MXCPP_NAME_HOST_CPP_VALUE)">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_HOST_TEST),$$$(MXCPP_NAME_HOST_CPP),".$(MXCPP_NAME_HOST_TEST_VALUE)">>$@
	@$(ECHO) SetVar $$$(MXCPP_NAME_HOST_JOBS),"$(MXCPP_NAME_HOST_JOBS_VALUE)">>$@
	@$(call MXCPP_AUTOGEN_FOOTER)
	@$(ECHO)   ... the DataSet setup script done.


define MXCPP_BUILD_DIRLIST
$(eval $(1) := .$(subst /,.,$(subst ./,,$(dir $(2)))))
$(if $(strip $(findstring $($(1)),$(MXCPP_DIRS_LIST))),,$(eval MXCPP_DIRS_LIST += $($(1))))
endef	# MXCPP_BUILD_DIRLIST

MXCPP_DIRS_LIST :=
$(foreach source,$(MXCPP_SRC_LIST),$(eval $(call MXCPP_BUILD_DIRLIST,MXCPP_DIR,$(source))))

MXCPP_DIR := $(MXCPP_DIRS_LIST)

MXCPP_DIRS_LIST :=
$(foreach source,$(MXCPP_EXTRA_INCLUDE),$(eval $(call MXCPP_BUILD_DIRLIST,MXCPP_DIR_EXTRA,$(source))))

MXCPP_DIR_EXTRA := $(filter-out $(MXCPP_DIR),$(MXCPP_DIRS_LIST))

MXCPP_DIRS_LIST :=
$(foreach dir,$(MXCPP_DIR_EXTRA),$(eval MXCPP_DIRS_LIST += $$$$$(MXCPP_NAME_TARGET_DIR),".$(MXCPP_CONFIG_SUFFIX)$(dir)",$$$$$(MXCPP_NAME_HOST_HPP)))
$(foreach dir,$(MXCPP_DIR),$(eval MXCPP_DIRS_LIST += $$$$$(MXCPP_NAME_TARGET_DIR),".$(MXCPP_CONFIG_SUFFIX)$(dir)",$$$$$(MXCPP_NAME_HOST_HPP) $$$$$(MXCPP_NAME_TARGET_DIR),".$(MXCPP_CONFIG_SUFFIX)$(dir)",$$$$$(MXCPP_NAME_HOST_INL) $$$$$(MXCPP_NAME_TARGET_DIR),"$(dir)",$$$$$(MXCPP_NAME_HOST_CPP)))
MXCPP_DIRS_LIST += \
$$$(MXCPP_NAME_TARGET_DIR),".$(MXCPP_CONFIG_SUFFIX).internal.",$$$(MXCPP_NAME_HOST_HPP)	\
$$$(MXCPP_NAME_TARGET_DIR),".$(MXCPP_CONFIG_SUFFIX).internal.",$$$(MXCPP_NAME_HOST_INL)	\
$$$(MXCPP_NAME_TARGET_DIR),".",$$$(MXCPP_NAME_HOST_TEST)	\
$$$(MXCPP_NAME_TARGET_DIR),".$(MXCPP_NAME_HOST_OBJLIB_VALUE)"	\
$$$(MXCPP_NAME_TARGET_DIR),".$(MXCPP_NAME_HOST_OBJLIB_VALUE).$(MXCPP_NAME_HOST_TEST_VALUE)"	\
$$$(MXCPP_NAME_TARGET_DIR),".",$$$(MXCPP_NAME_HOST_JOBS)

MXCPP_BINDIRS_LIST += \
$$$(MXCPP_NAME_TARGET_DIR),".$(MXCPP_NAME_HOST_LNKLIB_VALUE)"	\
$$$(MXCPP_NAME_TARGET_DIR),".$(MXCPP_NAME_HOST_LNKLIB_VALUE).$(MXCPP_NAME_HOST_TEST_VALUE)"

define MXCPP_RULE_DIRLIST
	$(ECHO).>>$@
	$(ECHO) SetVar $$DIRNAME,$(1)>>$@
	$(ECHO) include $(CURDIR)/MD$(2).$(MXCPP_FINALSCR_SUFF)>>$@

endef	# MXCPP_RULE_DIRLIST

# The directory initializer list.
$(MXCPP_DIRINIT_LIST):	$(MXCPP_DSSETUP_SCRIPT)
	@$(ECHO) - assembling the directory init list ...
	@$(call MXCPP_AUTOGEN_HEADER,Initialize directories on mainframe)
	@$(ECHO).>>$@
	@$(ECHO) * Setup the script>>$@
	@$(ECHO) include $(CURDIR)/$(MXCPP_DSSETUP_SCRIPT)>>$@
	@$(ECHO).>>$@
	@$(ECHO) global $$DIRNAME>>$@
	@$(ECHO).>>$@
	@$(foreach dir,$(MXCPP_DIRS_LIST),$(call MXCPP_RULE_DIRLIST,$(dir),text))
	@$(foreach dir,$(MXCPP_BINDIRS_LIST),$(call MXCPP_RULE_DIRLIST,$(dir),binary))
	@$(call MXCPP_AUTOGEN_FOOTER)
	@$(ECHO)   ... the directory init list done.

$(MXCPP_DIRINIT_SCRIPT):	../platform.ini
	@$(ECHO) - assembling the directory init script ...
	@$(call MXCPP_AUTOGEN_HEADER,Initialize directories on mainframe - full run with logging on)
	@$(ECHO) * Connect to mainframe>>$@
	@$(call MXCPP_RULE_CONNECT)
	@$(ECHO) * Run the directory list script>>$@
	@$(ECHO) include $(CURDIR)/$(MXCPP_DIRINIT_LIST)>>$@
	@$(call MXCPP_AUTOGEN_FOOTER)
	@$(ECHO)   ... the directory init script done.


# The login script.
# (created only once if it does not exist - user can adapt it and it should not
# be re-generated then)
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
	@$(ECHO) * The session login password>>$@
	@$(ECHO) SetVar $$HOSTPASSWORD,"">>$@
	@$(ECHO) * Warning: Storing the password is unsafe.>>$@
	@$(ECHO) *          You possibly can transfer the password setup to another file>>$@
	@$(ECHO) *          in safe location and include it here.>>$@
	@$(call MXCPP_AUTOGEN_FOOTER)
ifneq ($(strip $(EDITOR)),)
	-@$(EDITOR) $(MXCPP_LOGIN_SCRIPT)
endif
	@$(ECHO)   ... the login script done.


# The login script.
# (created only once if it does not exist - user can adapt it and it should not
# be re-generated then)
$(MXCPP_CONNECT_SCRIPT):
	@$(ECHO) - assembling the connect script ...
	@$(ECHO) * The connect script>$@
	@$(ECHO) * $(MXCPP_SCRIPT_COMMENT)>>$@
	@$(ECHO).>>$@
	@$(ECHO) * Adapt this connect script to your environment.>>$@
	@$(ECHO) * (additional connection tasks, e.g. dialing some other machine etc.)>>$@
	@$(ECHO).>>$@
	@$(call MXCPP_AUTOGEN_FOOTER)
ifneq ($(strip $(EDITOR)),)
	-@$(EDITOR) $(MXCPP_CONNECT_SCRIPT)
endif
	@$(ECHO)   ... the connect script done.


# EOF #
