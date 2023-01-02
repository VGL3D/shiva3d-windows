#ifndef LOADMODEL_H_INCLUDED
#define LOADMODEL_H_INCLUDED

#include "VGL/Libs/Libs.h"

void LoadScene(WindowFramework *window,PandaFramework framework)
{
  NodePath scene = window->load_model(framework.get_models(), "models/environment");
  scene.reparent_to(window->get_render());
  scene.set_scale(0.25, 0.25, 0.25);
  scene.set_pos(-8, 42, 0);

  NodePath pandaActor = window->load_model(framework.get_models(), "models/panda-model");
  pandaActor.set_scale(0.005);
  pandaActor.reparent_to(window->get_render());
}

#endif // LOADMODEL_H_INCLUDED
