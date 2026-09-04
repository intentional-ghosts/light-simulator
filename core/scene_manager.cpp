
#include "scene_manager.h"


scene_manager g_scene_manager; 

int scene_manager::object_counter = 0; 
  

void scene_manager::init_scene_manager()
{

    delta_time = 0.0f;
    last_frame = 0.0f;
    
}


void scene_manager::add_object_to_scene()
{
    

    //printf(" working");

    g_scene_manager.object_list[ object_counter ] = new cube( 1.0f, 0.0f, 0.0f, 1.0f ); 

    // name object
    
    g_scene_manager.object_list[ object_counter ] -> object_name = " object " + std::to_string( object_counter ); 

    if ( object_counter < MAX_OBJECTS )
    {
        //printf( " counter before incrementation = %d", g_scene_manager.object_counter );
        g_scene_manager.object_counter += 1;    
        //printf( "counter = %d ", g_scene_manager.object_counter );
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