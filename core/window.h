

#ifndef WINDOW_H // this is an include guard
#define WINDOW_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>
#include <glad/glad.h>
#include "input.h"
#include <stdbool.h>






void glfw_library_init( void );
void set_error_callback( void (* errorcallback)( int, const char * ));
void create_error_callBack( int error, const char* description );
int window_creation( int width, int height, const char * title );
void window_poll( void );
void window_color( float red, float green, float blue, float alpha );
void window_buffer_clear( void );
void window_swap( void );
void window_shutdown( void );
GLFWwindow * get_window( void );
HWND get_hwnd( void );
void load_glad( void ); 



#endif