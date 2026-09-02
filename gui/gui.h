
#ifndef GUI_H
#define GUI_H


#include <stdbool.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>




#if __cplusplus
extern "C" {
#endif


void gui_init( GLFWwindow * window ); 
void gui_new_frame();
void create_demo_window();
void object_creation_window();
void gui_render();
void gui_shutdown(); 
void set_dear_imgui_key_callback( GLFWwindow * window, int key, int scancode, int action, int mods );
void set_dear_imgui_scollwheel_callback( GLFWwindow * window ,double xoffset, double yoffset );
void set_dear_imgui_cursor_pos_callback( GLFWwindow * window, double current_xpos, double currect_ypos );
void set_dear_imgui_mouse_button_callback( GLFWwindow * window, int button, int action, int mods );
void set_dear_imgui_char_callback( GLFWwindow * window, unsigned int c );
int imgui_wants_mouse();
int imgui_wants_keyboard();


#if __cplusplus
}
#endif

#endif