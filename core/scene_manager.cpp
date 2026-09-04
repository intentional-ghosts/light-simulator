
#include "scene_manager.h"


scene_manager g_scene_manager; 

int scene_manager::object_counter = 0; 
int scene_manager::light_counter = 0; 
int scene_manager::object_in_existence = 0;

void scene_manager::init_scene_manager()
{

    delta_time = 0.0f;
    last_frame = 0.0f;
    
}


void scene_manager::add_object_to_scene()
{
    

    //printf(" working");

    g_scene_manager.object_list[ object_counter ] = new cube( ); 

    // name object
    
    g_scene_manager.object_list[ object_counter ] -> object_name = " object " + std::to_string( object_counter ); 

    if ( object_counter < MAX_OBJECTS )
    {
        //printf( " counter before incrementation = %d", g_scene_manager.object_counter );
        g_scene_manager.object_counter += 1; 
        g_scene_manager.object_in_existence += 1;  
        printf(" object_in_existence %d", g_scene_manager.object_in_existence);
        //printf( "counter = %d ", g_scene_manager.object_counter );
    }

    
     

}


void scene_manager::add_light_to_scene( )
{

     //printf(" working");

    g_scene_manager.light_list[ light_counter ] = new light(); 

    // name object
    
    g_scene_manager.light_list[ light_counter ] -> light_object_name = " object " + std::to_string( light_counter ); 

    if ( light_counter < MAX_LIGHT_OBJECTS )
    {
        //printf( " counter before incrementation = %d", g_scene_manager.light_counter );
        g_scene_manager.light_counter += 1;   
        g_scene_manager.object_in_existence += 1;  
        printf(" object_in_existence %d", g_scene_manager.object_in_existence);
        //printf( "counter = %d ", g_scene_manager.light_counter );
    }

  }

void scene_manager::clean_up_heap_memory()
{
    
    //printf(" calling clean up function");

    for ( int i = 0; i < MAX_OBJECTS; i++)
    {
        if ( g_scene_manager.object_list[i] != nullptr)
        {
            delete g_scene_manager.object_list[i]; 
            g_scene_manager.object_list[i] = nullptr;

        }
        
    }
    
    g_scene_manager.object_counter = 0;

}