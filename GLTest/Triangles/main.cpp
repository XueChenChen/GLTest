//
//  main.cpp
//  Triangles
//
//  Created by mac on 2019/8/15.
//  Copyright © 2019 mac. All rights reserved.
//

#include <iostream>
#include "GLFW/glfw3.h"

// Shaders
const GLchar* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
"}";
int main(int argc, const char * argv[]) {
    if (!glfwInit()) {
        return -1;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    GLFWwindow* window = glfwCreateWindow(640, 480, "三角形", NULL, NULL);
    if (window == nullptr) {
        printf("failed create GLFW windows");
        glfwGetTime();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    
    glViewport(0, 0, 640, 480);
    
    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glClearColor(0.5, 0.5, 0.5, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
