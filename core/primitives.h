#ifndef primitives_h
#define primitives_h

#include <glad/glad.h>
#include <stdbool.h>
#include "texture.h"
#include "shader.h"
#include "glm/glm.hpp"
#include <string>

struct mesh 
{
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;
    

    
};

struct cube : public mesh 
{
    glm::vec3 position = { 0.0f, 0.0f, 0.0f };
    glm::vec3 scale = { 1.0f, 1.0f, 1.0f };
    glm::vec3 rotation = { 0.0f, 0.0f, 0.0f };
    glm::vec4 color;
    basic_shader shader;
    std::string  object_name; 
    
    

    cube( float red, float green, float blue, float alpha )
    {

        color = glm::vec4(red, green, blue, alpha); 
        
        float vertex_data[] = 
        {
            // top 
            -0.5, 0.5, -0.5, color[0], color[1], color[2], color[3],
            -0.5, 0.5, 0.5,  color[0], color[1], color[2], color[3],
            0.5, 0.5, -0.5,  color[0], color[1], color[2], color[3],
            0.5, 0.5, 0.5,   color[0], color[1], color[2], color[3],

            // bottom 
            -0.5, -0.5, -0.5, color[0], color[1], color[2], color[3],
            -0.5, -0.5, 0.5,  color[0], color[1], color[2], color[3],
            0.5, -0.5, -0.5,  color[0], color[1], color[2], color[3],
            0.5, -0.5, 0.5,   color[0], color[1], color[2], color[3],

            // front
            0.5, 0.5, 0.5,     color[0], color[1], color[2], color[3],
            0.5, -0.5, 0.5,    color[0], color[1], color[2], color[3],
            -0.5, 0.5, 0.5,    color[0], color[1], color[2], color[3],
            -0.5, -0.5, 0.5,   color[0], color[1], color[2], color[3],

            // back
            0.5, 0.5, -0.5,     color[0], color[1], color[2], color[3],
            0.5, -0.5, -0.5,    color[0], color[1], color[2], color[3],
            -0.5, 0.5, -0.5,    color[0], color[1], color[2], color[3],
            -0.5, -0.5, -0.5,   color[0], color[1], color[2], color[3],

            // right 
            0.5, 0.5, -0.5,     color[0], color[1], color[2], color[3],
            0.5, 0.5, 0.5,      color[0], color[1], color[2], color[3],
            0.5, -0.5, -0.5,    color[0], color[1], color[2], color[3],
            0.5, -0.5, 0.5,     color[0], color[1], color[2], color[3],

            // left
            -0.5, 0.5, -0.5,    color[0], color[1], color[2], color[3],
            -0.5, 0.5, 0.5,     color[0], color[1], color[2], color[3],
            -0.5, -0.5, -0.5,   color[0], color[1], color[2], color[3],
            -0.5, -0.5, 0.5,    color[0], color[1], color[2], color[3],

        };

        unsigned int indices[] =
        {
            // top
            0, 1, 2,
            1, 3, 2,

            // bottom
            4, 5, 6,
            5, 7, 6,

            // front
            8, 9, 10,
            9, 11, 10,

            // back
            12, 13, 14,
            13, 15, 14,

            // right
            16, 17, 18,
            17, 19, 18,

            // left
            20, 21, 22,
            21, 23, 22
        };

    

        glGenVertexArrays( 1, &VAO);
        glBindVertexArray( VAO );

        glGenBuffers( 1, &VBO );
        glBindBuffer( GL_ARRAY_BUFFER, VBO );
        glBufferData( GL_ARRAY_BUFFER, sizeof( vertex_data ), vertex_data, GL_DYNAMIC_DRAW ); 
        
        glGenBuffers( 1, &EBO );
        glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBO );
        glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( indices ), indices, GL_DYNAMIC_DRAW ); 

        glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), ( void * )0 );
        glEnableVertexAttribArray( 0 );

        glVertexAttribPointer( 1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), ( void * )( 3 * sizeof(float) ) );

        glEnableVertexAttribArray( 1 );


    }

    void update_model_matrix();
    void upadte_view_matrix(); 
    void update_perspective_matrix(); 


};



#endif