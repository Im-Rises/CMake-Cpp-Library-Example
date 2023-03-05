/*
 * Code based on the ImGUi example code
 * https://github.com/ocornut/imgui/blob/master/examples/libs/emscripten/emscripten_mainloop_stub.h
 */

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <functional>
static std::function<void()> MainLoopForEmscriptenP;
static void MainLoopForEmscripten() { MainLoopForEmscriptenP(); }
#define EMSCRIPTEN_MAINLOOP_BEGIN MainLoopForEmscriptenP = [&]()
#define EMSCRIPTEN_MAINLOOP_END \
    ;                           \
    emscripten_set_main_loop(MainLoopForEmscripten, 0, true)
#else
#define EMSCRIPTEN_MAINLOOP_BEGIN
#define EMSCRIPTEN_MAINLOOP_END
#endif
