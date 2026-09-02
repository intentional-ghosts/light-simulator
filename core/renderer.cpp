
#include "renderer.h"
#include "primitives.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shader.h"
#include "texture.h"
#include "scene_manager.h"



void draw_scene( )
{   

    
    for ( int i = 0; i < g_scene_manager.object_counter; i++)
    {

        cube * cube_o = g_scene_manager.object_list[i];


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