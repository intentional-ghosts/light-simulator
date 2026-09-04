
#include "input.h"


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
    
    
    #ifdef IS_COMPUTER

        if ( button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS )
        {
            g_scene_manager.scene_cam.camera_is_moving = true;
            glfwSetInputMode( window, GLFW_CURSOR, GLFW_CURSOR_DISABLED );
            g_input_state.mouse_clicked = true;
        }

        if ( button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
        {
            g_scene_manager.scene_cam.camera_is_moving = false; 
            glfwSetInputMode( window, GLFW_CURSOR, GLFW_CURSOR_NORMAL );    

        }

    #endif


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


    #ifdef IS_LAPTOP
    
        if ( key == GLFW_KEY_G && action == GLFW_PRESS )
        {
            g_scene_manager.scene_cam.camera_is_moving = true;
            glfwSetInputMode( window, GLFW_CURSOR, GLFW_CURSOR_DISABLED );
            g_input_state.mouse_clicked = true;
            
        }

        if ( key == GLFW_KEY_G && mods == GLFW_MOD_CONTROL && action == GLFW_PRESS)
        {
           
            g_scene_manager.scene_cam.camera_is_moving = false; 
            glfwSetInputMode( window, GLFW_CURSOR, GLFW_CURSOR_NORMAL );     

        }
    
    #endif

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

    g_scene_manager.scene_cam.xoffset = current_x_pos;
    g_scene_manager.scene_cam.yoffset = currect_y_pos;


} 

void set_cursor_pos_callback( GLFWwindow * window, void( * mouse_callback_function)( GLFWwindow * , double, double) )
{
    glfwSetCursorPosCallback( window, mouse_callback_function);
} 

void create_scollwheel_callback( GLFWwindow * window, double xoffset, double yoffset )
{

    // camera in scene manager

    set_dear_imgui_scollwheel_callback( window, xoffset, yoffset);

    if ( imgui_wants_mouse() )
    {
        return;
    }

    g_scene_manager.scene_cam.fov -= (float)yoffset;

    if (  g_scene_manager.scene_cam.fov < 1.0f )
    {
        g_scene_manager.scene_cam.fov = 1.0f;
    }
    if (  g_scene_manager.scene_cam.fov > 90.0f )
    {
       g_scene_manager.scene_cam.fov = 90.0f; 
    }
    


}

void set_scoll_callback( GLFWwindow * window, void( * create_scollweel_callback )( GLFWwindow *, double, double ) )
{
    glfwSetScrollCallback( window, create_scollweel_callback );
}

void processing_keyboard_input( GLFWwindow * window )
{

    g_scene_manager.scene_cam.camera_speed = 3.0 * g_scene_manager.delta_time; 
    //printf(" camera speed = %f",g_scene_manager.scene_cam.camera_speed );
    glm::vec3 result; 

    if ( glfwGetKey( window, GLFW_KEY_W ) == GLFW_PRESS ) 
    {
        //printf( " camera pos before x = %f, y = %f, z = %f \n", g_scene_manager.scene_cam.camera_pos[0], g_scene_manager.scene_cam.camera_pos[1], g_scene_manager.scene_cam.camera_pos[2] );
        //printf( " rotation_vector before x = %f, y = %f, z = %f \n", g_scene_manager.scene_cam.rotation_vector[0], g_scene_manager.scene_cam.rotation_vector[1], g_scene_manager.scene_cam.rotation_vector[2] );

        result = g_scene_manager.scene_cam.rotation_vector * g_scene_manager.scene_cam.camera_speed;

        //printf( " rotation_vector before x = %f, y = %f, z = %f \n", result[0], result[1], result[2] );

        g_scene_manager.scene_cam.camera_pos += result;  

        //printf( " camera pos after x = %f, y = %f, z = %f \n", g_scene_manager.scene_cam.camera_pos[0], g_scene_manager.scene_cam.camera_pos[1], g_scene_manager.scene_cam.camera_pos[2] );

    }

    if (glfwGetKey( window, GLFW_KEY_S ) ==  GLFW_PRESS )
    {
        result = g_scene_manager.scene_cam.rotation_vector * g_scene_manager.scene_cam.camera_speed;
        g_scene_manager.scene_cam.camera_pos -= result; 

    }

    if ( glfwGetKey( window, GLFW_KEY_A ) ==  GLFW_PRESS )
    {
        result = g_scene_manager.scene_cam.cameras_x_axis * g_scene_manager.scene_cam.camera_speed;
        g_scene_manager.scene_cam.camera_pos -= result; 
    }

    if ( glfwGetKey( window, GLFW_KEY_D ) ==  GLFW_PRESS )
    {
        result = g_scene_manager.scene_cam.cameras_x_axis * g_scene_manager.scene_cam.camera_speed;
        g_scene_manager.scene_cam.camera_pos += result; 
    }
    

    bool ctrlPressed = ( glfwGetKey( window, GLFW_KEY_LEFT_CONTROL ) == GLFW_PRESS || glfwGetKey( window, GLFW_KEY_RIGHT_CONTROL ) == GLFW_PRESS );

    if ( ctrlPressed && glfwGetKey( window, GLFW_KEY_Q ) == GLFW_PRESS  )
    {
        result = g_scene_manager.scene_cam.cameras_y_axis * g_scene_manager.scene_cam.camera_speed;
        g_scene_manager.scene_cam.camera_pos += result; 
    }
    

    if ( ctrlPressed && glfwGetKey( window, GLFW_KEY_E ) ==  GLFW_PRESS  )
    {
        result = g_scene_manager.scene_cam.cameras_y_axis * g_scene_manager.scene_cam.camera_speed;
        g_scene_manager.scene_cam.camera_pos -= result; 
    }
    


}

void camera_is_moving( ) 
{

   // camera exists in the scene manager

    float x_offset =  g_scene_manager.scene_cam.xoffset - g_scene_manager.scene_cam.last_x_pos;  
    float y_offset = g_scene_manager.scene_cam.last_y_pos - g_scene_manager.scene_cam.yoffset; 

    g_scene_manager.scene_cam.last_x_pos =  g_scene_manager.scene_cam.xoffset;
    g_scene_manager.scene_cam.last_y_pos =  g_scene_manager.scene_cam.yoffset;

    x_offset *= g_scene_manager.scene_cam.rotation_sensitivity;
    y_offset *= g_scene_manager.scene_cam.rotation_sensitivity; 

    g_scene_manager.scene_cam.yaw += x_offset; 
    g_scene_manager.scene_cam.pitch += y_offset; 

    if(  g_scene_manager.scene_cam.pitch > 89.0f)
    {
        g_scene_manager.scene_cam.pitch = 89.0f;
    }

    if ( g_scene_manager.scene_cam.pitch < -89.0f)
    {
        g_scene_manager.scene_cam.pitch = -89.0f;
    }


}