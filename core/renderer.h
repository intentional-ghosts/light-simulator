
#ifndef RENDERER

#define RENDERER

#include <stdio.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "shader.h"
#include "texture.h"
#include <stdbool.h>
#include "renderer.h"
#include "primitives.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "scene_manager.h"
#include <glm/gtc/type_ptr.hpp>

#ifdef __cplusplus
extern "C" {
#endif


void draw_scene( GLFWwindow * window );


#if __cplusplus
}
#endif

#endif