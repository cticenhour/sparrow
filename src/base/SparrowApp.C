#include "SparrowApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
SparrowApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

SparrowApp::SparrowApp(InputParameters parameters) : MooseApp(parameters)
{
  SparrowApp::registerAll(_factory, _action_factory, _syntax);
}

SparrowApp::~SparrowApp() {}

void
SparrowApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<SparrowApp>(f, af, s);
  Registry::registerObjectsTo(f, {"SparrowApp"});
  Registry::registerActionsTo(af, {"SparrowApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
SparrowApp::registerApps()
{
  registerApp(SparrowApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
SparrowApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  SparrowApp::registerAll(f, af, s);
}
extern "C" void
SparrowApp__registerApps()
{
  SparrowApp::registerApps();
}
