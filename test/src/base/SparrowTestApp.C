//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "SparrowTestApp.h"
#include "SparrowApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
SparrowTestApp::validParams()
{
  InputParameters params = SparrowApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

SparrowTestApp::SparrowTestApp(InputParameters parameters) : MooseApp(parameters)
{
  SparrowTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

SparrowTestApp::~SparrowTestApp() {}

void
SparrowTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  SparrowApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"SparrowTestApp"});
    Registry::registerActionsTo(af, {"SparrowTestApp"});
  }
}

void
SparrowTestApp::registerApps()
{
  registerApp(SparrowApp);
  registerApp(SparrowTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
SparrowTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  SparrowTestApp::registerAll(f, af, s);
}
extern "C" void
SparrowTestApp__registerApps()
{
  SparrowTestApp::registerApps();
}
