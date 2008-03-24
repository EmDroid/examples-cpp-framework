##
# @file
#
# Build the Demo C++ Framework project documentation.
#
# @author Emil Maskovsky
#
# The targets to build different documentation configurations:
# @li @b all: build all documentation configurations
# @li @b public: build the public documentation
# @li @b internal: build the internal documentation
#
# @li @b clean: delete the generated documentation
#


# The default target.
public:


# The options.
include makefile.ini


# Suppose Linux if not set up for Windows.
$(if $(strip $(RM)),,$(eval RM := rm))
$(if $(strip $(NULL)),,$(eval NULL := /dev/null))


# Macros for hiding command output.
NOOUT := >$(NULL)
NOERROUT := 2>$(NULL)


all:	public internal


# Build the public documentation.
public $(MXCPP_CHM_NAME):	clean_public
	-@echo Creating the [public] documentation ...
	@$(DC) $(DCFLAGS) Doxyfile $(DC_OUTPUT)
	-@echo ... the [public] documentation is done.

# Build the internal documentation.
internal internal/$(MXCPP_CHM_NAME):	clean_internal
	-@echo Creating the [internal] documentation ...
	@$(DC) $(DCFLAGS) Doxyfile.internal $(DC_OUTPUT)
	-@echo ... the [internal] documentation is done.

# Start the main documentation.
run:	run_public

# Startup the public documentation.
run_public:	$(MXCPP_CHM_NAME)
	@$(MXCPP_CHM_NAME)

# Startup the internal documentation.
run_internal:
	@internal/$(MXCPP_CHM_NAME)

# Clean the generated documentation.
clean:	clean_public clean_internal

# Clean the public documentation files.
clean_public:
	-@echo Cleaning the [public] documentation ...
	-@cd html $(NOERROUT) && $(RM) *.html $(NOERROUT)
	-@cd html $(NOERROUT) && $(RM) *.css $(NOERROUT)
	-@cd html $(NOERROUT) && $(RM) *.gif $(NOERROUT)
	-@cd html $(NOERROUT) && $(RM) *.png $(NOERROUT)
	-@cd html $(NOERROUT) && $(RM) index.* $(NOERROUT)
	-@rmdir $(MXCPP_HTMLDOC_ROOT) $(NOERROUT)
	-@$(RM) $(MXCPP_CHM_NAME) $(NOERROUT)
	-@$(RM) warnings.log $(NOERROUT)
	-@echo ... the cleaning of the [public] documentation is done.

# Clean the internal documentation files.
clean_internal:
	-@echo Cleaning the [internal] documentation ...
	-@cd internal $(NOERROUT) && cd html $(NOERROUT) && $(RM) *.html $(NOERROUT)
	-@cd internal $(NOERROUT) && cd html $(NOERROUT) && $(RM) *.css $(NOERROUT)
	-@cd internal $(NOERROUT) && cd html $(NOERROUT) && $(RM) *.gif $(NOERROUT)
	-@cd internal $(NOERROUT) && cd html $(NOERROUT) && $(RM) *.png $(NOERROUT)
	-@cd internal $(NOERROUT) && cd html $(NOERROUT) && $(RM) index.* $(NOERROUT)
	-@cd internal $(NOERROUT) && rmdir $(MXCPP_HTMLDOC_ROOT) $(NOERROUT)
	-@cd internal $(NOERROUT) && $(RM) $(MXCPP_CHM_NAME) $(NOERROUT)
	-@$(RM) warnings.internal.log $(NOERROUT)
	-@rmdir internal $(NOERROUT)
	-@echo ... the cleaning of the [internal] documentation is done.


.PHONY:	all public internal run run_public run_internal clean clean_public clean_internal

# EOF #
