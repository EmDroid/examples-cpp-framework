# $Id$ #

##
# @file
#
# Makefile for the Demo C++ Framework project
#     - batch processing makefile for Microsoft platform.
#
# This makefile is mainly serving for testing purposes - building targets with
# all supported available systems under current platform.
#
# @author Emil Maskovsky
#


include ../bakedefs.ini


# The list of systems, which will be checked for current platform.
MXCPP_BATCHMAKE_SYSTEMS := dos16 win16 win32 win64
#  dos32
# dos 32-bit extender currently not tested, while there are difficulties running these executables under Windows


$(foreach target,$(MXCPP_BATCHMAKE_TARGETS),$(eval $(call MXCPP_BATCHMAKE_RULES_TARGET,$(target),$(MXCPP_BATCHMAKE_SYSTEMS))))


# EOF #
