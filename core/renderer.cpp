
#include "renderer.h"



void draw_scene( GLFWwindow * window )
{   

    
    for ( int i = 0; i < g_scene_manager.object_counter; i++)
    {

        cube * cube_o = g_scene_manager.object_list[i];

        // need to grab the uniform of the model matrix 
       

        if ( cube_o != nullptr)
        {

            cube_o -> update_model_matrix();

            g_scene_manager.scene_cam.update_view_matrix();
            g_scene_manager.scene_cam.update_window_resolution( window );
            g_scene_manager.scene_cam.update_perspective_matrix(); 

            GLint model_location = glGetUniformLocation( g_scene_manager.shader.shader_program, "model");

            glUseProgram( g_scene_manager.shader.shader_program );
            glUniformMatrix4fv( model_location, 1, GL_FALSE, glm::value_ptr( cube_o -> model ) );

            GLint view_location = glGetUniformLocation( g_scene_manager.shader.shader_program, "view");

            glUseProgram( g_scene_manager.shader.shader_program );
            glUniformMatrix4fv( view_location, 1, GL_FALSE, glm::value_ptr( g_scene_manager.scene_cam.view ) );

            GLint prospective_location = glGetUniformLocation(g_scene_manager.shader.shader_program, "projection");

            glUseProgram( g_scene_manager.shader.shader_program );
            glUniformMatrix4fv( prospective_location, 1, GL_FALSE, glm::value_ptr( g_scene_manager.scene_cam.projection ) );

            glUseProgram( g_scene_manager.shader.shader_program );
            glBindVertexArray( cube_o -> VAO );
            glDrawElements( GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0 );
            glBindVertexArray( 0 );
            glUseProgram( 0 );
        }
        
      


    }
    
}