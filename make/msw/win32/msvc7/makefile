
define MXCPP_GMAKE_OLD

$(warning /==================================================\)
$(warning |                 !!! ERROR !!!                    |)
$(warning |--------------------------------------------------|)
$(warning |     !!! Incompatible MAKE tool detected !!!      |)
$(warning |  This build system requires "GNU make" tool, at  |)
$(warning |  least the version 3.80 (try 'make --version')   |)
$(warning \==================================================/)

endef

# Check the $(MAKE) compatibility.
$(if $(strip $(MAKEFILE_LIST)),,$(eval $(call MXCPP_GMAKE_OLD)))


# Makefile definitions.
include makefile.ini

# Start parent make.
include ../platform.mak

# EOF #
