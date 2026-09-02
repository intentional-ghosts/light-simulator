#include <cstdio>
#include "primitives.h"
#include "scene_manager.h"
#include "gui.h"
#include <glm/glm.hpp>



void cube::update_model_matrix()
{
    glm::vec4 postion = glm::vec4( g_scene_manager.object_list[g_gui_state.current_object_selected] -> position, 1.0f );

    g_scene_manager.object_list[g_gui_state.current_object_selected] -> model  = glm::mat4(1.0f); 

    auto& model_matrix = g_scene_manager.object_list[g_gui_state.current_object_selected]->model;

    model_matrix = glm::translate(model_matrix, position);      

    g_scene_manager.object_list[g_gui_state.current_object_selected] -> model *= position; 


}

void cube::upadte_view_matrix()
{

}

void cube::update_perspective_matrix()
{

}