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


all:	public internal


# Build the public documentation.
public $(MXCPP_CHM_NAME):	clean_public
	-@echo Creating the [public] documentation ...
	@$(DC) $(DCFLAGS) Doxyfile
	-@echo ... the [public] documentation is done.

# Build the internal documentation.
internal internal/$(MXCPP_CHM_NAME):	clean_internal
	-@echo Creating the [internal] documentation ...
	@$(DC) $(DCFLAGS) Doxyfile.internal
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
	-@cd html && $(RM) *.html
	-@cd html && $(RM) *.css
	-@cd html && $(RM) *.gif
	-@cd html && $(RM) *.png
	-@cd html && $(RM) index.*
	-@rmdir $(MXCPP_HTMLDOC_ROOT)
	-@$(RM) $(MXCPP_CHM_NAME)
	-@$(RM) warnings.log
	-@echo ... the cleaning of the [public] documentation is done.

# Clean the internal documentation files.
clean_internal:
	-@echo Cleaning the [internal] documentation ...
	-@cd internal && cd html && $(RM) *.html
	-@cd internal && cd html && $(RM) *.css
	-@cd internal && cd html && $(RM) *.gif
	-@cd internal && cd html && $(RM) *.png
	-@cd internal && cd html && $(RM) index.*
	-@cd internal && rmdir $(MXCPP_HTMLDOC_ROOT)
	-@cd internal && $(RM) $(MXCPP_CHM_NAME)
	-@$(RM) warnings.internal.log
	-@rmdir internal
	-@echo ... the cleaning of the [internal] documentation is done.


.PHONY:	all public internal run run_public run_internal clean clean_public clean_internal

# EOF #
