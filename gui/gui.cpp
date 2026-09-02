
#include <iostream>
#include <string.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include <windows.h>
#include <string.h>
#include "gui.h"
#define NFD_OVERRIDE_RECENT_WITH_DEFAULT
#include <nfd_glfw3.h>
#include <nfd.h>
#include "input.h"
#include "scene_manager.h"

void gui_init( GLFWwindow * window )
{
    // Setup Dear ImGui context
    
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

// Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL( window , false);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
    ImGui_ImplOpenGL3_Init("#version 330");

}

void gui_new_frame()
{
    // (Your code calls glfwPollEvents())
    // ...
    // Start the Dear ImGui frame

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();

    ImGui::NewFrame();

    //ImGui::ShowDemoWindow(); // Show demo window! :)

}

void create_demo_window()
{
    
    if ( g_input_state.show_gui == true )
    {
        ImGui::ShowDemoWindow();
    }

}


void object_creation_window()
{
    
    bool p_open = true;



    ImGui::Begin( " object creation", &p_open);

    
        if (ImGui::Button("create_cube", ImVec2( 200, 200) ) )
        {
            
            g_scene_manager.add_object_to_scene(); 

        }
        


    ImGui::End();


}

void gui_render()
{
    // Rendering
    // (Your code clears your framebuffer, renders your other stuff etc.)
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    // (Your code calls glfwSwapBuffers() etc.)

}

void gui_shutdown()
{

    static bool shutdown_called = false;
    
    if (shutdown_called) {
        return;  // Already shut down, don't do it again
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();


    shutdown_called = true;
    // printf("ImGui shutdown complete\n");

}

void set_dear_imgui_key_callback( GLFWwindow * window, int key, int scancode, int action, int mods )
{
    ImGui_ImplGlfw_KeyCallback( window, key, scancode, action, mods );
}

void set_dear_imgui_scollwheel_callback( GLFWwindow * window ,double current_x_pos, double currect_y_pos )
{
    ImGui_ImplGlfw_ScrollCallback( window, current_x_pos, currect_y_pos );
    
}

void set_dear_imgui_cursor_pos_callback( GLFWwindow * window, double xoffset, double yoffset )
{
    ImGui_ImplGlfw_CursorPosCallback( window, xoffset, yoffset );
}

void set_dear_imgui_mouse_button_callback( GLFWwindow * window, int button, int action, int mods )
{
    ImGui_ImplGlfw_MouseButtonCallback( window, button, action, mods );
}

void set_dear_imgui_char_callback(  GLFWwindow * window, unsigned int c )
{
    ImGui_ImplGlfw_CharCallback( window, c );
} 

int imgui_wants_mouse()
{
    return ImGui::GetIO().WantCaptureMouse;
}

int imgui_wants_keyboard()
{
    return ImGui::GetIO().WantCaptureKeyboard;
}

