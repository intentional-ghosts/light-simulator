
#ifndef TEXTURE_H
#define TEXTURE_H


#include "loader_library/stb_image.h"
#include <stdbool.h>
typedef struct 
{
    unsigned int id;
    char name[30];
    char image_path[255]; 

} texture;

typedef struct 
{
    unsigned int id;
    
     
} cubemap_texture;

typedef struct 
{

   
    unsigned int id;


} shadow_map;

texture create_texture( char * name, char * image_path );  
cubemap_texture create_cubemap_texture();
void fix_file_path( char  path[255] );

#endif