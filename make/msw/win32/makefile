##
# @file
#
# Makefile for the Demo C++ Framework project
#     - Windows 32 global makefile.
#
# This makefile is mainly serving for testing purposes - building targets with
# all supported available compilers under current system.
#
# @author Emil Maskovsky
#


# The main targets, which will be available for system batch processing.
MXCPP_MAIN_TARGETS := all test clean cleanall


# The list of compilers, which will be checked for current system.
MXCPP_LIST_COMPILERS := gcc bcc dmc msvc6 msvc7 msvc8

MXCPP_BATCH_msvc6_SETUP := setmsvc6
MXCPP_BATCH_msvc7_SETUP := setmsvc7
MXCPP_BATCH_msvc8_SETUP := setmsvc8


# Declare batch rules for single target and single compiler.
#
# @param $(1) The single target from the $(MXCPP_MAIN_TARGETS) list.
# @param $(2) The single compiler from the $(MXCPP_LIST_COMPILERS) list.
#
define MXCPP_BATCH_RULES_TARGET_COMPILER

$(1):	$(1)_$(2)

$(1)_$(2):
	@echo *** Running the target [$(1)] for the compiler [$(2)] ... *** 
	@$(if $(strip $(MXCPP_BATCH_$(2)_SETUP)),$(MXCPP_BATCH_$(2)_SETUP) && )$(MAKE) -C $(2) --no-print-directory -$(MAKEFLAGS) $(1)
	@echo *** ... done the target [$(1)] for the compiler [$(2)]. ***

endef	# MXCPP_BATCH_RULES_TARGET_COMPILER


# Declare batch rules for single target.
#
# @param $(1) The single target from the $(MXCPP_MAIN_TARGETS) list.
#
define MXCPP_BATCH_RULES_TARGET

$(1):

$(foreach compiler,$(MXCPP_LIST_COMPILERS),$(call MXCPP_BATCH_RULES_TARGET_COMPILER,$(1),$(compiler)))

endef	# MXCPP_BATCH_RULES_TARGET


$(foreach target,$(MXCPP_MAIN_TARGETS),$(eval $(call MXCPP_BATCH_RULES_TARGET,$(target))))


# EOF #
