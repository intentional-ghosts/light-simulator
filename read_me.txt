this file contains functions and header files that you can use to build the basis of the open gl window so you can get start faster 

i would like to add a cube map to the world instead of a basic back ground color but that for later. 


void update_camera_matrices( GLFWwindow * window )
{
    state_of_all_structs * structs = (state_of_all_structs *)glfwGetWindowUserPointer( window );

    vec3 rotation_vector = { sin( glm_rad( structs -> data -> yaw ) ) * cos( glm_rad( structs -> data -> pitch ) ), sin( glm_rad( structs -> data -> pitch ) ), -cos( glm_rad( structs -> data -> yaw ) ) * cos( glm_rad(structs -> data -> pitch) ) }; 

        glm_normalize( rotation_vector );

        glm_vec3_copy( rotation_vector, structs -> camera -> rotation_vector_values );

        glm_vec3_cross( structs -> camera -> rotation_vector_values, structs -> camera -> up_direction_vector_reference, structs -> camera -> cameras_x_axis );
        
        glm_vec3_cross( structs -> camera -> cameras_x_axis, structs -> camera -> cameras_front_direction_vector, structs -> camera -> cameras_y_axis);

        glm_vec3_normalize( structs -> camera -> cameras_x_axis );
        glm_vec3_normalize( structs -> camera -> cameras_y_axis );

        glm_vec3_add( structs -> camera -> camera_pos, structs -> camera -> rotation_vector_values, structs -> camera -> cameras_target_postion_vector );

        glm_mat4_identity( structs -> camera -> view );

        glm_lookat( structs -> camera -> camera_pos, structs -> camera -> cameras_target_postion_vector, structs -> camera -> up_direction_vector_reference, structs -> camera -> view );
        


        glfwGetWindowSize( window, &structs -> camera -> window_width, &structs -> camera -> window_height );
        glm_perspective( glm_rad( structs -> data -> fov ), (float)structs -> camera -> window_width / (float)structs -> camera -> window_height ,0.1f ,100.0f, structs -> camera -> projection );


}


  state_of_all_structs * structs = (state_of_all_structs *)glfwGetWindowUserPointer( window );

    set_dear_imgui_scollwheel_callback( window, xoffset, yoffset);

    if ( imgui_wants_mouse() )
    {
        return;
    }

    structs -> data -> fov -= (float)yoffset;

    if ( structs -> data -> fov < 1.0f )
    {
        structs -> data -> fov = 1.0f;
    }
    if ( structs -> data -> fov > 90.0f )
    {
        structs -> data -> fov = 90.0f; 
    }


    float currect_frame = glfwGetTime(); 
        data.delta_time = currect_frame - data.last_frame;  
        data.last_frame = currect_frame; 

    void camera_is_moving( GLFWwindow * window ) 
{

    state_of_all_structs * structs = (state_of_all_structs *)glfwGetWindowUserPointer( window );

    float x_offset = structs -> data -> xoffset - structs -> data -> last_x_pos;  
    float y_offset = structs -> data -> last_y_pos - structs -> data -> yoffset; 
    structs -> data -> last_x_pos = structs -> data -> xoffset;
    structs -> data -> last_y_pos = structs -> data -> yoffset;

    float rotation_sensitivity = 0.1f;

    x_offset *= rotation_sensitivity;
    y_offset *= rotation_sensitivity; 

    structs -> data -> yaw += x_offset; 
    structs -> data -> pitch += y_offset; 

    if( structs -> data -> pitch > 89.0f)
    {
        structs -> data -> pitch = 89.0f;
    }

    if ( structs -> data -> pitch < -89.0f)
    {
        structs -> data -> pitch = -89.0f;
    }

}




