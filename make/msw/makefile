# $Id$ #

##
# @file
#
# Makefile for the Demo C++ Framework project
#     - Microsoft platforms batch processing.
#
# This makefile is mainly serving for testing purposes - building targets with
# all supported available systems under current platform.
#
# @author Emil Maskovsky
#


include ../bakedefs.ini


# The list of systems, which will be checked for current platform.
MXCPP_BATCHMAKE_SYSTEMS := dos16 dos32 win32


$(foreach target,$(MXCPP_BATCHMAKE_TARGETS),$(eval $(call MXCPP_BATCHMAKE_RULES_TARGET,$(target),$(MXCPP_BATCHMAKE_SYSTEMS))))


# EOF #
