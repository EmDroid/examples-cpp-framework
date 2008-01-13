##
# @file
#
# Makefile for the Demo C++ Framework project
#     - batch processing makefile for HP-Unix.
#
# This makefile is mainly serving for testing purposes - building targets with
# all supported available compilers under current system.
#
# @author Emil Maskovsky
#


include ../../bakedefs.ini


# The list of compilers, which will be checked for current system.
MXCPP_BATCHMAKE_COMPILERS := gcc32 gcc64

MXCPP_BATCHMAKE_gcc64_SETUP := PATH=.:/opt/hp-gcc64-3.4.5/bin:$(PATH)


$(foreach target,$(MXCPP_BATCHMAKE_TARGETS),$(eval $(call MXCPP_BATCHMAKE_RULES_TARGET,$(target),$(MXCPP_BATCHMAKE_COMPILERS))))


# EOF #
