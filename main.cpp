#include <iostream>
#include "Shader.h"
#include <glfw3.h>
#include "gameobjects/Ball.h"
#include "gameobjects/Platform.h"

void resize_callback(GLFWwindow* win,int w,int h);
void kbd_callback(GLFWwindow* win, int key,int scancode,int action,int mod);

Platform platform;//("platform.vert","platform.frag");

int main() {


    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(200,300,"Breakout",NULL,NULL);
    if(window==NULL)
    {
        std::cout<<"Error while creating window!"<<std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout<<"Error while initializing GLAD"<<std::endl;
        glfwTerminate();
        return -1;
    }

    int attributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, & attributes);
    std::cout<<"Supported "<<attributes<<" of vertex attributes"<<std::endl;
    glViewport(0,0,200,300);
    platform=Platform("platform.vert","platform.frag");
    Ball ball("ball.vert","ball.frag");

    glfwSetKeyCallback(window,kbd_callback);
    glfwSetFramebufferSizeCallback(window,resize_callback);
    std::cout<<"Entering main loop"<<std::endl;
    while(!glfwWindowShouldClose(window))
    {
        glClearColor(.0,.0,.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        platform.draw();
        ball.update(platform);
        ball.draw();


        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}

void kbd_callback(GLFWwindow* win, int key,int scancode,int action,int mod)
{
    if(action == GLFW_REPEAT)
    {
        switch (key) {
            case GLFW_KEY_RIGHT:
                platform.moveRight();
                break;
            case GLFW_KEY_LEFT:
                platform.moveLeft();
                break;
        }
    }
    if(action == GLFW_PRESS)
    {
        switch(key)
        {
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(win,1);
                break;
            case GLFW_KEY_D:
                glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
                break;
            case GLFW_KEY_F:
                glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
                break;
            case GLFW_KEY_RIGHT:
                platform.moveRight();
                break;
            case GLFW_KEY_LEFT:
                platform.moveLeft();
                break;
        }
    }
}

void resize_callback(GLFWwindow* win,int w,int h)
{
    glfwSetWindowSize(win,200,300);
}
