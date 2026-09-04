
#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <cstdio>


struct basic_shader
{
 
  unsigned int shader_program; 
   
  basic_shader()
  {  
   
  }


  void init_shader_data();

};

//shader create_shader(void);
///shader create_light_shader();
//shader create_cubemap_shader();
//shader create_ShadowMap_shader();




#endif