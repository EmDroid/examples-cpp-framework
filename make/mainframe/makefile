##
# @file
#
# Makefile for the Demo C++ Framework project
#     - batch processing makefile for IBM Mainframe platform.
#
# This makefile is mainly serving for testing purposes - building targets with
# all supported available systems under current platform.
#
# @author Emil Maskovsky
#


include ../bakedefs.ini


# The list of systems, which will be checked for current platform.
MXCPP_BATCHMAKE_SYSTEMS := os390


$(foreach target,$(MXCPP_BATCHMAKE_TARGETS),$(eval $(call MXCPP_BATCHMAKE_RULES_TARGET,$(target),$(MXCPP_BATCHMAKE_SYSTEMS))))


# EOF #
