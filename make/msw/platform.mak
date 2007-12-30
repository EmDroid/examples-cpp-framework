##
# @file
#
# Makefile for the Demo C++ Framework project
#     - Microsoft systems platform dependent options.
#
# @author Emil Maskovsky
#


# Append sub-platform configuration flags.
$(foreach compiler,$(MXCPP_COMPILERS_LIST),\
	$(if $(strip $(MXCPP_$(compiler)FLAGS_SUBPLATFORM)),\
		$(eval MXCPP_$(compiler)FLAGS_PLATFORM += $(MXCPP_$(compiler)FLAGS_SUBPLATFORM))))


# Start global make.
include ../../../global.mak

# EOF #
