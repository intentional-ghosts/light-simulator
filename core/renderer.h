
#ifndef RENDERER

#define RENDERER

#include <stdio.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "shader.h"
#include "texture.h"
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif


void draw_scene(  );


#if __cplusplus
}
#endif

#endif