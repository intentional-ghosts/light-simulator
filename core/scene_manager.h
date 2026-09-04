
#ifndef SCENE_MANAGER

#define SCENE_MANAGER


#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "shader.h"
#include "primitives.h"
#include <cstdio>

constexpr int MAX_OBJECTS = 100;
constexpr int MAX_LIGHT_OBJECTS = 100; 

struct scene_manager
{

  static int object_counter; // needed to update the model matrix
  static int light_counter;  // needed to update the model matrix
  static int object_in_existence; // used in the draw_scene_function so you know how many object exist. 

  float current_frame;
  float last_frame;
  float delta_time;
  cube * object_list[ MAX_OBJECTS ] = { nullptr }; 
  light * light_list[ MAX_LIGHT_OBJECTS ] = { nullptr };
  camera scene_cam;
  basic_shader shader;

  // i want to create the camera here so its in the scene manager. 

  scene_manager()
  {

  }

  void init_scene_manager(); 
  void add_object_to_scene( );
  void add_light_to_scene( ); 
  void clean_up_heap_memory( ); 

   
};

extern scene_manager g_scene_manager; 


#endif