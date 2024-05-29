###############################################################################
################### MOOSE Application Standard Makefile #######################
###############################################################################
#
# Optional Environment variables
# MOOSE_DIR        - Root directory of the MOOSE project
# TMAP8_DIR        - Root directory of the TMAP8 project
#
###############################################################################
# Use the MOOSE submodule if it exists and MOOSE_DIR is not set
MOOSE_SUBMODULE    := $(CURDIR)/moose
ifneq ($(wildcard $(MOOSE_SUBMODULE)/framework/Makefile),)
  MOOSE_DIR        ?= $(MOOSE_SUBMODULE)
else
  MOOSE_DIR        ?= $(shell dirname `pwd`)/moose
endif

# Use the TMAP8 submodule if it exists and TMAP8_DIR is not set
TMAP8_SUBMODULE    := $(CURDIR)/TMAP8
ifneq ($(wildcard $(TMAP8_SUBMODULE)/Makefile),)
  TMAP8_DIR        ?= $(TMAP8_SUBMODULE)
else
  TMAP8_DIR        ?= $(shell dirname `pwd`)/TMAP8
endif

# framework
FRAMEWORK_DIR      := $(MOOSE_DIR)/framework
include $(FRAMEWORK_DIR)/build.mk
include $(FRAMEWORK_DIR)/moose.mk

################################## MODULES ####################################
# To use certain physics included with MOOSE, set variables below to
# yes as needed.  Or set ALL_MODULES to yes to turn on everything (overrides
# other set variables).

ALL_MODULES                 := no

CHEMICAL_REACTIONS          := yes
CONTACT                     := no
ELECTROMAGNETICS            := no
EXTERNAL_PETSC_SOLVER       := no
FLUID_PROPERTIES            := yes
FSI                         := no
FUNCTIONAL_EXPANSION_TOOLS  := no
GEOCHEMISTRY                := no
HEAT_TRANSFER               := yes
LEVEL_SET                   := no
MISC                        := yes
NAVIER_STOKES               := yes
OPTIMIZATION                := no
PERIDYNAMICS                := no
PHASE_FIELD                 := yes
POROUS_FLOW                 := no
RAY_TRACING                 := yes
REACTOR                     := no
RDG                         := yes
RICHARDS                    := no
SCALAR_TRANSPORT            := yes
SOLID_MECHANICS             := yes
SOLID_PROPERTIES            := yes
STOCHASTIC_TOOLS            := no
THERMAL_HYDRAULICS          := yes
XFEM                        := no

include $(MOOSE_DIR)/modules/modules.mk
###############################################################################

# TMAP8
APPLICATION_DIR    := $(TMAP8_DIR)
APPLICATION_NAME   := TMAP8
GEN_REVISION       := no
include            $(FRAMEWORK_DIR)/app.mk

# Sparrow
APPLICATION_DIR    := $(CURDIR)
APPLICATION_NAME   := sparrow
BUILD_EXEC         := yes
GEN_REVISION       := no
include            $(FRAMEWORK_DIR)/app.mk

###############################################################################
# Additional special case targets should be added here
