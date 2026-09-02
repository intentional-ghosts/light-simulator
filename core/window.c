
#include "window.h"
#include <stdio.h>
#define NFD_OVERRIDE_RECENT_WITH_DEFAULT
#include <nfd_glfw3.h>
#include <nfd.h>



static GLFWwindow * g_window = NULL;
static HWND g_hwnd = NULL;

void glfw_library_init(void)
{
    if (!glfwInit())
    {
        fprintf( stderr,"glfw init failed");   
    }
    
}

void set_error_callback(void (* error_callback)( int, const char* ))
{   
    //printf("linked call back");
    glfwSetErrorCallback( error_callback );
}

void create_error_callBack( int error, const char* description )
{
    
    fprintf(stderr,"Error, %s \n", description);
}

void window_color( float red , float green, float blue, float alpha )
{
    glClearColor( red, green, blue, alpha );
    
}

void window_buffer_clear(void)
{
    // this clears the buffer ever frame so you can load new things to the screen
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // perset work on later when you get the idea of this better
}

int window_creation(int width, int height, const char * title)
{
   
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    g_window = glfwCreateWindow( width, height,title,NULL,NULL);

    g_hwnd = glfwGetWin32Window( g_window );

    if (!g_window)
    {
        fprintf(stderr,"window creation failed");
        glfwTerminate();
        return 0;
    }

    glfwMakeContextCurrent(g_window);
    glfwSwapInterval(1); // Enable vsync



    if( !gladLoadGLLoader( ( GLADloadproc ) glfwGetProcAddress ) )
    {
        printf( "glad library didnt load" );
    }
    
    create_framebuffer_callback( g_window, width, height);

    set_error_callback(create_error_callBack );
    set_input_callback( get_window() , create_key_callback );
    setframebuffer(get_window(), create_framebuffer_callback );
    SetMouseButtonCallback( get_window(), mouse_button_callback );
    set_cursor_pos_callback( get_window(), create_mouse_cursor_callback );
    set_scoll_callback( get_window(), create_scollwheel_callback );
    set_char_callback( get_window(), create_char_callback ); 

    
    NFD_Init(); 
    NFD_SetDisplayPropertiesFromGLFW();
    return 1;
}

void load_glad()
{
    
}

void window_poll(void)
{
    glfwPollEvents();
}

void window_swap()
{
    glfwSwapBuffers(g_window);
}

void window_shutdown(void)
{

    
    NFD_Quit();
    // used to destroy the window not everything els. 
    glfwDestroyWindow(g_window);
    // terminateing all of the glfw functions
    glfwTerminate();
}
 
GLFWwindow * get_window( void )
{
    return g_window;
}

HWND get_hwnd( void )
{
    return g_hwnd;
}