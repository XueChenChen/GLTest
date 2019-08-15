//
//  main.cpp
//  GLTest
//
//  Created by mac on 2019/8/15.
//  Copyright © 2019 mac. All rights reserved.
//

#include <iostream>
#include "GLFW/glfw3.h"

const GLuint WIDTH = 800, HEIGHT = 600;

int main(int argc, const char * argv[]) {
    if(!glfwInit()){
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    
    auto window = glfwCreateWindow(WIDTH, HEIGHT, "Hello Window", nullptr, nullptr);
    
    if (nullptr == window) {
        std::cout << "Failed to create GLFW windows" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    glViewport(0, 0, WIDTH, HEIGHT);
    
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        
        //do rendering
        glClearColor(0.2, 0.3, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(window);
    }
    
    glfwTerminate();
    return 0;
}
