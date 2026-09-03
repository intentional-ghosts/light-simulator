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

void cube::upadte_view_matrix()
{

}

void cube::update_perspective_matrix()
{

}