

#include "primitives.h"
#include "scene_manager.h"
#include "gui.h"



void cube::update_model_matrix()
{

        for ( int i = 0; i < g_scene_manager.object_counter; i++)
        {
            glm::vec3 position = glm::vec3( g_scene_manager.object_list[i] -> position);
            glm::vec3 scale = glm::vec3( g_scene_manager.object_list[i] -> scale);
            glm::vec3 rotation = glm::vec3( g_scene_manager.object_list[i] -> rotation);
            g_scene_manager.object_list[i] -> model = glm::mat4(1.0f);

            g_scene_manager.object_list[i] -> model = glm::scale( g_scene_manager.object_list[i] -> model , scale );

            g_scene_manager.object_list[i] -> model  = glm::rotate( g_scene_manager.object_list[i] -> model, glm::radians( g_scene_manager.object_list[i] -> rotation[0] ), glm::vec3 ( 1.0f, 0.0f, 0.0f ) );
            g_scene_manager.object_list[i] -> model  = glm::rotate( g_scene_manager.object_list[i] -> model, glm::radians( g_scene_manager.object_list[i] -> rotation[1] ), glm::vec3 ( 0.0f, 1.0f, 0.0f ) );
            g_scene_manager.object_list[i] -> model  = glm::rotate( g_scene_manager.object_list[i] -> model, glm::radians( g_scene_manager.object_list[i] -> rotation[2] ), glm::vec3 ( 0.0f, 0.0f, 1.0f ) );

            g_scene_manager.object_list[i] -> model = glm::translate( g_scene_manager.object_list[i] -> model , position );
            

        }
}


void light::update_light_model_matrix()
{

    for ( int i = 0; i < g_scene_manager.light_counter; i++)
    {
        glm::vec3 position = glm::vec3( g_scene_manager.light_list[i] -> position);
        
        glm::vec3 scale = glm::vec3( g_scene_manager.light_list[i] -> scale);

        glm::vec3 rotation = glm::vec3( g_scene_manager.light_list[i] -> rotation);
        
        g_scene_manager.light_list[i] -> model = glm::mat4(1.0f);

        g_scene_manager.light_list[i] -> model = glm::scale( g_scene_manager.light_list[i] -> model , scale );

        g_scene_manager.light_list[i] -> model  = glm::rotate( g_scene_manager.light_list[i] -> model, glm::radians( g_scene_manager.light_list[i] -> rotation[0] ), glm::vec3 ( 1.0f, 0.0f, 0.0f ) );

        g_scene_manager.light_list[i] -> model  = glm::rotate( g_scene_manager.light_list[i] -> model, glm::radians( g_scene_manager.light_list[i] -> rotation[1] ), glm::vec3 ( 0.0f, 1.0f, 0.0f ) );
        
        g_scene_manager.light_list[i] -> model  = glm::rotate( g_scene_manager.light_list[i] -> model, glm::radians( g_scene_manager.light_list[i] -> rotation[2] ), glm::vec3 ( 0.0f, 0.0f, 1.0f ) );

        g_scene_manager.light_list[i] -> model = glm::translate( g_scene_manager.light_list[i] -> model , position );
        
    }
}


void camera::init_camera_data()
{
    window_resolution = 0.0f;
    xoffset = 0.0;
    yoffset = 0.0;
    yaw = 0.0f;
    pitch = 1.0f;
    rotation_sensitivity = 0.1f;
    fov = 60;
    last_x_pos = 400;
    last_y_pos = 300;
    camera_is_moving = false; 
}

void camera::update_view_matrix()
{

    rotation_vector = { sin( glm::radians( yaw ) ) * cos( glm::radians( pitch ) ), sin( glm::radians( pitch ) ), -cos( glm::radians( yaw ) ) * cos( glm::radians( pitch ) ) }; 

    rotation_vector = glm::normalize( rotation_vector );


    cameras_x_axis = glm::cross( rotation_vector, up_direction_vector );
        
    cameras_y_axis = glm::cross( cameras_x_axis,  front_direction_vector );

    cameras_x_axis = glm::normalize( cameras_x_axis );
    cameras_y_axis = glm::normalize( cameras_y_axis );

    target_postion_vector = camera_pos + rotation_vector;

    view = glm::mat4(1.0f);

    view = glm::lookAt( camera_pos,  target_postion_vector,  up_direction_vector );
        

   

}

void camera::update_perspective_matrix()
{

    projection = glm::mat4(1.0f);

    projection = glm::perspective( glm::radians( fov ), window_resolution ,     0.1f ,100.0f);


} 

void camera::update_window_resolution( GLFWwindow * window )
{   
    int window_width;
    int window_height;
    glfwGetWindowSize( window, &window_width, &window_height );

    window_resolution = (float)window_width / (float)window_height; 

}