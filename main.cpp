#include <cstdio>
#include <cstdlib>
#include "window.h"
#include "input.h"
#include "primitives.h"
#include "renderer.h"
#include "shader.h"
#include "texture.h"
#include "gui.h"

int main(void)
{
    glfw_library_init();

    if (!window_creation(1280, 720, "light simulator"))
    {
        return -1;
    }

    gui_init(get_window());

    while (!glfwWindowShouldClose(get_window()))
    {
       
        window_poll();
        gui_new_frame();
        // rendering will go here later
        window_color(0.1f, 0.1f, 0.15f, 1.0f);
        window_buffer_clear();

        object_creation_window(); 


        gui_render();

    
        window_swap();
    }

    gui_shutdown();
    window_shutdown();
    return 0;
}

#ifdef _WIN32
#include <windows.h>
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    return main();
}
#endif