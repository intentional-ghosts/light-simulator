
#include "shader.h"


// try to create the shader struct inside of the mesh or cube object constructor so the cube as a shader. 



/*
shader create_light_shader()
{
    const char * vertex_shader_source_code = 
    "#version 330 core\n"
    "layout(location = 0) in vec3 a_pos;\n" 
    "layout(location = 1) in vec4 a_color;\n"
    "layout(location = 2) in vec2 a_texture;\n"
    "out vec4 frag_color;\n" 

    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"

    "void main()\n"
    "{\n"
        "gl_Position =  projection * view * model * vec4(a_pos,1.0);\n"
        
    "}\n";

    const char * fragment_shader_source_code = 
    "#version 330 core\n"
    "in vec4 frag_color;\n"
    "out vec4 outputed_color;\n"
    "uniform vec4 light_color;\n"

    "void main()\n"
    "{\n"
        
        "outputed_color = light_color;\n"
        
    "}\n";


    shader light_source_shader;

    light_source_shader.vertex_shader = glCreateShader( GL_VERTEX_SHADER );
    glShaderSource( light_source_shader.vertex_shader, 1, &vertex_shader_source_code, 0);
    glCompileShader( light_source_shader.vertex_shader );

    int success;
    char info_log[512];
    glGetShaderiv( light_source_shader.vertex_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog( light_source_shader.vertex_shader, 512, NULL, info_log);
        printf("vertex shader error: %s\n", info_log);
    }


    light_source_shader.fragment_shader = glCreateShader( GL_FRAGMENT_SHADER );
    glShaderSource( light_source_shader.fragment_shader, 1, &fragment_shader_source_code, 0);
    glCompileShader( light_source_shader.fragment_shader );
    
    glGetShaderiv( light_source_shader.fragment_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(light_source_shader.fragment_shader, 512, NULL, info_log);
        printf("fragment shader error: %s\n", info_log);
    }



    light_source_shader.shader_program = glCreateProgram();

    glAttachShader( light_source_shader.shader_program, light_source_shader.vertex_shader );
    glAttachShader( light_source_shader.shader_program, light_source_shader.fragment_shader );

    glLinkProgram( light_source_shader.shader_program); 

    glDeleteShader( light_source_shader.vertex_shader );
    glDeleteShader( light_source_shader.fragment_shader );


    return light_source_shader;
}

shader create_cubemap_shader()
{

    const char * vertex_shader_source_code = 
    "#version 330 core\n"
    "layout(location = 0) in vec3 a_pos;\n" 

    "out vec3 texture_coord;\n" 
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"

    "void main()\n"
    "{\n"
        "texture_coord = a_pos;\n"
        "vec4 pos = projection * view * vec4(a_pos, 1.0);\n"
        "gl_Position = pos.xyww;\n"
        
    "}\n";

    const char * fragment_shader_source_code = 
    "#version 330 core\n"
    "in vec3 texture_coord;\n"
    "out vec4 outputed_color;\n"
    "uniform samplerCube skybox;\n"

    "void main()\n"
    "{\n"
        
       "outputed_color = texture( skybox, texture_coord );\n"
        
    "}\n";


    shader cube_map_shader;

    cube_map_shader.vertex_shader = glCreateShader( GL_VERTEX_SHADER );
    glShaderSource( cube_map_shader.vertex_shader, 1, &vertex_shader_source_code, 0);
    glCompileShader( cube_map_shader.vertex_shader );

    int success;
    char info_log[512];
    glGetShaderiv( cube_map_shader.vertex_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog( cube_map_shader.vertex_shader, 512, NULL, info_log);
        printf("vertex shader error: %s\n", info_log);
    }


    cube_map_shader.fragment_shader = glCreateShader( GL_FRAGMENT_SHADER );
    glShaderSource( cube_map_shader.fragment_shader, 1, &fragment_shader_source_code, 0);
    glCompileShader( cube_map_shader.fragment_shader );
    
    glGetShaderiv( cube_map_shader.fragment_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(cube_map_shader.fragment_shader, 512, NULL, info_log);
        printf("fragment shader error: %s\n", info_log);
    }



    cube_map_shader.shader_program = glCreateProgram();

    glAttachShader( cube_map_shader.shader_program, cube_map_shader.vertex_shader );
    glAttachShader( cube_map_shader.shader_program, cube_map_shader.fragment_shader );

    glLinkProgram( cube_map_shader.shader_program); 

    glDeleteShader( cube_map_shader.vertex_shader );
    glDeleteShader( cube_map_shader.fragment_shader );


    return cube_map_shader;
    
}

shader create_ShadowMap_shader()
{
    const char * vertex_shader_source_code = 
    "#version 330 core\n"
    "layout(location = 0) in vec3 a_pos;\n" 

    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"

    "void main()\n"
    "{\n"
    
        "gl_Position = projection * view * model * vec4( a_pos, 1.0);\n"
        
    "}\n";

    const char * fragment_shader_source_code = 
    "#version 330 core\n"

    "void main()\n"
    "{\n"
        
        "gl_FragDepth = gl_FragCoord.z;\n"
        
    "}\n";


    shader shadow_map;

    shadow_map.vertex_shader = glCreateShader( GL_VERTEX_SHADER );
    glShaderSource( shadow_map.vertex_shader, 1, &vertex_shader_source_code, 0);
    glCompileShader( shadow_map.vertex_shader );

    int success;
    char info_log[512];
    glGetShaderiv( shadow_map.vertex_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog( shadow_map.vertex_shader, 512, NULL, info_log);
        printf("vertex shader error: %s\n", info_log);
    }


    shadow_map.fragment_shader = glCreateShader( GL_FRAGMENT_SHADER );
    glShaderSource( shadow_map.fragment_shader, 1, &fragment_shader_source_code, 0);
    glCompileShader( shadow_map.fragment_shader );
    
    glGetShaderiv( shadow_map.fragment_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shadow_map.fragment_shader, 512, NULL, info_log);
        printf("fragment shader error: %s\n", info_log);
    }



    shadow_map.shader_program = glCreateProgram();

    glAttachShader( shadow_map.shader_program, shadow_map.vertex_shader );
    glAttachShader( shadow_map.shader_program, shadow_map.fragment_shader );

    glLinkProgram( shadow_map.shader_program); 

    glDeleteShader( shadow_map.vertex_shader );
    glDeleteShader( shadow_map.fragment_shader );


    return shadow_map;
}

*/