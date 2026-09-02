
#ifndef SHADER_H
#define SHADER_H
#include <glad/glad.h>
#include <cstdio>


struct basic_shader
{
 
  unsigned int shader_program; 
   
  basic_shader()
  {  
    // local because they are destroyed any way
    unsigned int vertex_shader;
    unsigned int fragment_shader;

    const char * vertex_shader_source_code = 
    "#version 330 core\n"
    "layout(location = 0) in vec3 a_pos;\n" 
    "layout(location = 1) in vec4 a_color;\n"
    "out vec4 frag_color;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
  
    "void main()\n"
    "{\n"

      "gl_Position = vec4(a_pos, 1.0);\n"
      "frag_color = a_color;\n"
        
    "}\n";

    const char * fragment_shader_source_code = 
    "#version 330 core\n"
    "in vec4 frag_color;\n"
    "out vec4 outputed_color;\n"
 
    "void main()\n"
    "{\n"
    
      "outputed_color = frag_color;\n"

    "}\n";


    

    vertex_shader = glCreateShader( GL_VERTEX_SHADER );
    glShaderSource( vertex_shader, 1, &vertex_shader_source_code, 0);
    glCompileShader( vertex_shader );

    int success;
    char info_log[512];
    glGetShaderiv( vertex_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
      glGetShaderInfoLog( vertex_shader, 512, NULL, info_log);
      printf("vertex shader error: %s\n", info_log);
    }


    fragment_shader = glCreateShader( GL_FRAGMENT_SHADER );
    glShaderSource( fragment_shader, 1, &fragment_shader_source_code, 0);
    glCompileShader( fragment_shader );
    
    glGetShaderiv( fragment_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragment_shader, 512, NULL, info_log);
        printf("fragment shader error: %s\n", info_log);
    }



    shader_program = glCreateProgram();

    glAttachShader( shader_program, vertex_shader );
    glAttachShader( shader_program, fragment_shader );

    glLinkProgram( shader_program); 

    int link_success;
    glGetProgramiv( shader_program, GL_LINK_STATUS, &link_success );
    if ( !link_success )
    {
      char info_log[512];
      glGetProgramInfoLog( shader_program, 512, NULL, info_log );
      printf("shader link error: %s\n", info_log);
      
    }

    glDeleteShader( vertex_shader );
    glDeleteShader( fragment_shader );
      
  }

};

//shader create_shader(void);
///shader create_light_shader();
//shader create_cubemap_shader();
//shader create_ShadowMap_shader();




#endif