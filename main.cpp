//#include <cstdio>
#include <cstdlib>
#include "window.h"
#include "input.h"
#include "primitives.h"
#include "renderer.h"
#include "shader.h"
#include "texture.h"
#include "gui.h"
#include "scene_manager.h"

int main(void)
{
    glfw_library_init();

    if (!window_creation(1280, 720, "light simulator"))
    {
        return -1;
    }

    gui_init(get_window());

    g_scene_manager.init_scene_manager(); 
    g_scene_manager.shader.init_shader_data();
    g_scene_manager.scene_cam.init_camera_data();

    while (!glfwWindowShouldClose(get_window()))
    {
        
        g_scene_manager.current_frame = glfwGetTime(); 
        g_scene_manager.delta_time =  g_scene_manager.current_frame - g_scene_manager.last_frame;  
        g_scene_manager.last_frame =  g_scene_manager.current_frame; 
      

        window_poll();
        gui_new_frame();
        // rendering will go here later
        window_color(0.1f, 0.1f, 0.15f, 1.0f);
        window_buffer_clear();

        processing_keyboard_input( get_window( ) ); 
        
        if ( g_input_state.mouse_clicked )
        {  
            g_scene_manager.scene_cam.last_x_pos = g_scene_manager.scene_cam.xoffset;
            g_scene_manager.scene_cam.last_y_pos = g_scene_manager.scene_cam.yoffset;
            g_input_state.mouse_clicked = false;
        }

        if( g_scene_manager.scene_cam.camera_is_moving )
        {
            camera_is_moving( );
        };

        create_demo_window();

        hierarchy_window();
        inspector_window();
        object_creation_window();
        
        draw_scene( get_window() );


        gui_render();

        window_swap();
    }

    gui_shutdown();
    g_scene_manager.clean_up_heap_memory(); 
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