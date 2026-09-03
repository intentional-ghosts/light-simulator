#include <cstdio>
#include "primitives.h"
#include "scene_manager.h"
#include "gui.h"





void cube::update_model_matrix()
{

    if ( g_gui_state.current_object_selected != -1)
    {

        for ( int i = 0; i < g_scene_manager.object_counter; i++)
        {
            glm::vec3 position = glm::vec3( g_scene_manager.object_list[i] -> position);

            g_scene_manager.object_list[i] -> model = glm::mat4(1.0f);

            g_scene_manager.object_list[i] -> model = glm::translate( g_scene_manager.object_list[i] -> model , position);

        }
        
       

    }
   


}

void camera::update_view_matrix()
{

    glm::vec3 rotation_vector = { sin( glm::radians( yaw ) ) * cos( glm::radians( pitch ) ), sin( glm::radians( pitch ) ), -cos( glm::radians( yaw ) ) * cos( glm::radians( pitch ) ) }; 

    glm::normalize( rotation_vector );


    glm::cross(rotation_vector, up_direction_vector,  cameras_x_axis );
        
    glm::cross( cameras_x_axis,  front_direction_vector, cameras_y_axis);

    glm::normalize( cameras_x_axis );
    glm::normalize( cameras_y_axis );

    target_postion_vector = camera_pos + rotation_vector;

    view = glm::mat4(1.0f)

    glm::lookat( camera_pos,  cameras_target_postion_vector,  up_direction_vector_reference,  view );
        

   

}


void camera::update_perspective_matrix()
{

    projection = glm::mat4(1.0f);

    glm::perspective( glm::radians( fov ), window_resolution ,0.1f ,100.0f,  projection );


} 

void camera::update_window_resolution( GLFWwindow * window )
{   
    int window_width;
    int window_height;
    glfwGetWindowSize( window, &window_width, &window_height );

    window_resolution = (float)window_width / (float)window_height; 

}