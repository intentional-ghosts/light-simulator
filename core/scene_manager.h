
#ifndef SCENE_MANAGER

#define SCENE_MANAGER

#include <cstdio>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "shader.h"
#include "texture.h"
#include "primitives.h"

constexpr int MAX_OBJECTS = 100;

struct scene_manager
{

  static int object_counter;
  cube * object_list[ MAX_OBJECTS ] = { nullptr }; 

  void add_object_to_scene( ); 
  void clean_up_heap_memory( ); 

   
};

extern scene_manager g_scene_manager; 


#endif