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


include ../../bakedefs.ini


# The list of compilers, which will be checked for current system.
MXCPP_BATCHMAKE_COMPILERS := gcc bcc dmc msvc6 msvc7 msvc8 watcom

MXCPP_BATCHMAKE_msvc6_SETUP := setmsvc6
MXCPP_BATCHMAKE_msvc7_SETUP := setmsvc7
MXCPP_BATCHMAKE_msvc8_SETUP := setmsvc8


$(foreach target,$(MXCPP_BATCHMAKE_TARGETS),$(eval $(call MXCPP_BATCHMAKE_RULES_TARGET,$(target),$(MXCPP_BATCHMAKE_COMPILERS))))


# EOF #
