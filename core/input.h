#ifndef INPUT_H
#define INPUT_H

#include <GLFW/glfw3.h>
#include <stdbool.h>
#include "gui.h"


#ifdef __cplusplus
extern "C" {
#endif

void setframebuffer(GLFWwindow *window, void (*framebuffer_callback)(GLFWwindow*, int, int) );
void SetMouseButtonCallback(GLFWwindow *window, void (*mouse_button_callback)(GLFWwindow*, int, int, int) );
void create_framebuffer_callback(GLFWwindow *window, int width, int height);
void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
void set_input_callback( GLFWwindow * window, void ( *create_key_callback_function ) ( GLFWwindow *, int, int, int ,int ) );
void create_key_callback(  GLFWwindow * window, int key, int scancode, int action, int mods);
void set_char_callback( GLFWwindow * window,  void ( *create_char_callback ) ( GLFWwindow *, unsigned int ) );
void create_char_callback( GLFWwindow * window, unsigned int c );
void create_mouse_cursor_callback( GLFWwindow * window, double current_xpos, double currect_ypos ); 
void set_cursor_pos_callback( GLFWwindow * window, void( * mouse_callback_function)( GLFWwindow * , double, double) ); 
void set_scoll_callback( GLFWwindow * window, void( * create_scollweel_callback )( GLFWwindow *, double, double ) );
void create_scollwheel_callback( GLFWwindow * window, double xoffset, double yoffset );




#if __cplusplus
}
#endif

#endif