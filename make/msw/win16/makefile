##
# @file
#
# Makefile for the Demo C++ Framework project
#     - Windows 16 global makefile.
#
# This makefile is mainly serving for testing purposes - building targets with
# all supported available compilers under current system.
#
# @author Emil Maskovsky
#


include ../../bakedefs.ini


# The list of compilers, which will be checked for current system.
MXCPP_BATCHMAKE_COMPILERS := watcom


$(foreach target,$(MXCPP_BATCHMAKE_TARGETS),$(eval $(call MXCPP_BATCHMAKE_RULES_TARGET,$(target),$(MXCPP_BATCHMAKE_COMPILERS))))


# EOF #
