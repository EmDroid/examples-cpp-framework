##
# @file
#
# Makefile for the Demo C++ Framework project
#     - batch processing makefile for HP-Unix (Itanium).
#
# This makefile is mainly serving for testing purposes - building targets with
# all supported available compilers under current system.
#
# @author Emil Maskovsky
#


include ../../bakedefs.ini


# The list of compilers, which will be checked for current system.
MXCPP_BATCHMAKE_COMPILERS := acc32 acc64 gcc32 gcc64


$(foreach target,$(MXCPP_BATCHMAKE_TARGETS),$(eval $(call MXCPP_BATCHMAKE_RULES_TARGET,$(target),$(MXCPP_BATCHMAKE_COMPILERS))))


# EOF #
