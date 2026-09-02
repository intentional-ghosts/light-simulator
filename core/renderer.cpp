
#include "renderer.h"
#include "primitives.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shader.h"
#include "texture.h"
#include "scene_manager.h"
#include <glm/gtc/type_ptr.hpp>



void draw_scene( )
{   

    
    for ( int i = 0; i < g_scene_manager.object_counter; i++)
    {

        cube * cube_o = g_scene_manager.object_list[i];

        // need to grab the uniform of the model matrix 
        cube_o -> update_model_matrix();

        GLint model_location = glGetUniformLocation( cube_o->shader.shader_program, "model");

        glUseProgram( cube_o -> shader.shader_program );
        glUniformMatrix4fv( model_location, 1, GL_FALSE, glm::value_ptr( cube_o -> model ) );

        if ( cube_o != nullptr)
        {
            glUseProgram( cube_o -> shader.shader_program );
            glBindVertexArray( cube_o -> VAO );
            glDrawElements( GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0 );
            glBindVertexArray( 0 );
            glUseProgram( 0 );
        }
        
      


    }
    
}