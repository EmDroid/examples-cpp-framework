##
# @file
#
# Makefile for the Demo C++ Framework project
#     - UNIX systems platform dependent options.
#
# @author Emil Maskovsky
#


# Append sub-platform configuration flags.
$(foreach compiler,$(MXCPP_COMPILERS_LIST),\
	$(if $(strip $(MXCPP_$(compiler)FLAGS_SYSTEM)),\
		$(eval MXCPP_$(compiler)FLAGS_PLATFORM += $(MXCPP_$(compiler)FLAGS_SYSTEM))))


# Start global make.
include ../../../global.mak

# EOF #
