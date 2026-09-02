#include <stdio.h>
#include <glad/glad.h>
#include "input.h"
#include <string.h>
#include "gui.h"


#define base_force 5.0f // should be a net force for all forces acting on the object 
input_state g_input_state = {0}; 


// in input.c — genuinely reusable versions, no engine dependencies
void setframebuffer( GLFWwindow *window, void ( *framebuffer_callback )( GLFWwindow*, int, int ) )
{
    glfwSetFramebufferSizeCallback(window, framebuffer_callback);
}

void SetMouseButtonCallback( GLFWwindow *window, void ( *mouse_button_callback )( GLFWwindow*, int, int, int ) )
{
    glfwSetMouseButtonCallback(window, mouse_button_callback);
}

void create_framebuffer_callback( GLFWwindow *window, int width, int height )
{
    glViewport(0, 0, width, height);
}

void mouse_button_callback( GLFWwindow *window, int button, int action, int mods )
{
    set_dear_imgui_mouse_button_callback( window, button, action, mods ); 
}

void set_input_callback( GLFWwindow * window, void(* key_callback_function)( GLFWwindow *, int, int, int ,int ))
{
    //printf("in fuinction"); 

    glfwSetKeyCallback(window, key_callback_function);
}

void create_key_callback( GLFWwindow * window, int key, int scancode, int action, int mods )
{

    

    set_dear_imgui_key_callback( window, key, scancode, action, mods);

    if ( imgui_wants_keyboard() )
    {
        return;
    }


    if ( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS )
    {
        glfwSetWindowShouldClose( window, 1 );

    }


    if ( key == GLFW_KEY_V && action == GLFW_PRESS)
    {   

        g_input_state.show_gui = true;
    }
    
    if ( key == GLFW_KEY_H && action == GLFW_PRESS)
    {   

        g_input_state.show_gui = false;
    }


}

void set_char_callback( GLFWwindow * window,  void ( *create_char_callback ) ( GLFWwindow *, unsigned int ) )
{
    glfwSetCharCallback( window , create_char_callback );
}

void create_char_callback(  GLFWwindow * window, unsigned int c )
{
    set_dear_imgui_char_callback( window, c); 
}
// ment to be cursor pos call back 
void create_mouse_cursor_callback( GLFWwindow * window ,double current_x_pos, double currect_y_pos )
{

    set_dear_imgui_cursor_pos_callback( window, current_x_pos, currect_y_pos);

    if ( imgui_wants_mouse() )
    {
        return;
    }

} 

void set_cursor_pos_callback( GLFWwindow * window, void( * mouse_callback_function)( GLFWwindow * , double, double) )
{
    glfwSetCursorPosCallback( window, mouse_callback_function);
} 

void create_scollwheel_callback( GLFWwindow * window, double xoffset, double yoffset )
{

    

    set_dear_imgui_scollwheel_callback( window, xoffset, yoffset);

    if ( imgui_wants_mouse() )
    {
        return;
    }

    


}

void set_scoll_callback( GLFWwindow * window, void( * create_scollweel_callback )( GLFWwindow *, double, double ) )
{
    glfwSetScrollCallback( window, create_scollweel_callback );
}
