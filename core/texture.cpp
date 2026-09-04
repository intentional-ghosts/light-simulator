#include <stdio.h>
#define STB_IMAGE_IMPLEMENTATION
#include "texture.h"
#include "glad/glad.h"


texture create_texture( char * name, char * image_path )
{
    
    texture texture_o; 

    strcpy( texture_o.name , name );
    strcpy( texture_o.image_path, image_path );

    fix_file_path( texture_o.image_path );  

    int height, width, nr_channels;
    
    stbi_set_flip_vertically_on_load(1);

    //c:/Users/kris4/OneDrive/Saved Pictures/back ground for harverd project 0 game.jpg for labtop textures 
    //C:/Users/kris4/OneDrive/Saved_Pictures/Space-Exploration-102719-1440x960.jpg
    unsigned char * data = stbi_load( texture_o.image_path, &width, &height, &nr_channels, 0 );

    //printf("%s\n", texture_o.name );
    //printf("%s\n", texture_o.image_path );
    //printf("channels = %d\n", nr_channels );


    glGenTextures(1, &texture_o.id );
    glBindTexture( GL_TEXTURE_2D, texture_o.id );

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    if (data)
    {
        
        switch (nr_channels)
        {
        case 1 :

            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
            glTexImage2D( GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, data); 
            glGenerateMipmap(GL_TEXTURE_2D); 

            break;
        case 2 :

            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
            glTexImage2D( GL_TEXTURE_2D, 0, GL_RG, width, height, 0, GL_RG, GL_UNSIGNED_BYTE, data); 
            glGenerateMipmap(GL_TEXTURE_2D); 

            break;
        case 3 :

            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
            glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data); 
            glGenerateMipmap(GL_TEXTURE_2D); 

            break;
        case 4 :

            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
            glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data); 
            glGenerateMipmap(GL_TEXTURE_2D); 

            break;

        default:
            printf("nothing was chosen");
            break;
        }

    }
    else
    {
        printf(" failed to load texture"); 
        printf("Reason: %s\n", stbi_failure_reason() ); 
    }
    
    stbi_image_free(data);
    

    glBindTexture( GL_TEXTURE_2D, 0);

    return texture_o; 

}   

cubemap_texture create_cubemap_texture()
{
    
    cubemap_texture cubemap_o = {0};

    

    char face_textures[6][255] = 
    {
        "C:/Users/kris4/OneDrive/Saved_Pictures/ulukai/ulukai/corona_rt.png",
        "C:/Users/kris4/OneDrive/Saved_Pictures/ulukai/ulukai/corona_lf.png",
        "C:/Users/kris4/OneDrive/Saved_Pictures/ulukai/ulukai/corona_up.png",
        "C:/Users/kris4/OneDrive/Saved_Pictures/ulukai/ulukai/corona_dn.png",
        "C:/Users/kris4/OneDrive/Saved_Pictures/ulukai/ulukai/corona_bk.png",
        "C:/Users/kris4/OneDrive/Saved_Pictures/ulukai/ulukai/corona_ft.png"
        
    };

    int height, width, nr_channels;

    stbi_set_flip_vertically_on_load(1);

    
    glGenTextures(1, &cubemap_o.id );
    glBindTexture( GL_TEXTURE_CUBE_MAP, cubemap_o.id );

    for (int i = 0; i < sizeof(face_textures) / sizeof(face_textures[0]) ; i++)
    {
        
        unsigned char * data = stbi_load( face_textures[i], &width, &height, &nr_channels, 0 );

        if (data)
        {
        
            switch (nr_channels)
            {
            case 1 :

                glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
                glTexImage2D( GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, data); 
                stbi_image_free(data);

                break;
            case 2 :

                glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
                glTexImage2D( GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RG, width, height, 0, GL_RG, GL_UNSIGNED_BYTE, data); 
                stbi_image_free(data);

                break;
            case 3 :

                glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
                glTexImage2D( GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data); 
                stbi_image_free(data);

                break;
            case 4 :

                glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
                glTexImage2D( GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data); 
                stbi_image_free(data);


                break;
            default:

                printf("nothing was chosen");
                stbi_image_free(data);

                break;
            }

        }
        else
        {
            printf("failed to load texture number %d \n", i); 
            printf("Reason: %s\n", stbi_failure_reason() ); 
        }

    }
    

    glGenerateMipmap( GL_TEXTURE_CUBE_MAP ); 
   

    glTexParameteri( GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

    glTexParameteri( GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE );


    glBindTexture( GL_TEXTURE_CUBE_MAP, 0 );

   
    return cubemap_o;
}

void fix_file_path( char  path[255] )
{
    int read = 0;
    int write = 0;

    while (path[read] != '\0')
    {
        // Remove quotation marks
        if (path[read] != '"')
        {
            // Convert backslashes to forward slashes
            if (path[read] == '\\')
            {
                path[write] = '/';
            }
            else
            {
                path[write] = path[read];
            }

            write++;
        }

        read++;
    }

    // Null terminate the new string
    path[write] = '\0';
}