
#include "VGL/Libs/Libs.h"
#include "VGL/Loader/LoadModel.h"

PT(AsyncTaskManager) taskMgr = AsyncTaskManager::get_global_ptr();
PT(ClockObject) globalClock = ClockObject::get_global_clock();
NodePath camera;
NodePath pandaActor, pandaActor2;
WindowFramework* window;
AnimControlCollection anim_collection;

int i = -72, j = -2, k = 0.14;

AsyncTask::DoneStatus SpinCameraTask(GenericAsyncTask* task, void* data)
{
    //window->setup_trackball();
    Sleep(1);
    pandaActor.set_pos(5, j, 1);
    // pandaActor.
    // pandaActor2.set_pos(5,i,1);
    i += 1;
    j -= 1;
    k += 0.14;
    std::cout << window->get_graphics_window()->get_pointer(0).get_x() << "\t";
    std::cout << window->get_graphics_window()->get_pointer(0).get_y() << "\n";
    if (j == -37 && i == -37)
    {
        std::cout << "Boom";
    }
    else
    {
        return AsyncTask::DS_cont;
    }
}

int main(int argc, char* argv[])
{
    PandaFramework framework;
    framework.open_framework(argc, argv);
    framework.set_window_title("Window1");
    window = framework.open_window();
    window->setup_trackball();
    //camera = window->get_camera_group();

    //here main work
    NodePath scene = window->load_model(framework.get_models(), "models/environment");
    scene.reparent_to(window->get_render());
    scene.set_scale(0.25, 0.25, 0.25);
    scene.set_pos(0, 0, 0);

    pandaActor = window->load_model(framework.get_models(), "models/panda-model");
    pandaActor.set_scale(0.005);

    pandaActor2 = window->load_model(framework.get_models(), "models/panda-model");
    pandaActor2.set_scale(0.005);
    //    pandaActor.set_pos(-5,-40,1);
    //    pandaActor2.set_pos(5,-20,1);
    pandaActor.reparent_to(window->get_render());
    pandaActor2.reparent_to(window->get_render());

    std::cout << pandaActor.get_pos();

    window->load_model(pandaActor, "models/panda-walk4");
    window->load_model(pandaActor2, "models/panda-walk4");

    //taskMgr->add(new GenericAsyncTask("walk the panda", &SpinCameraTask, NULL));
    framework.main_loop();
    framework.close_framework();
    return (0);
}
