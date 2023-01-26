#include <iostream>
#include "Shader.h"
#include <glfw3.h>
#include "gameobjects/Ball.h"
#include "gameobjects/Platform.h"
#include "gameobjects/structs.h"

struct planeCollection
{
private:
    const float start_x = -.875;
    const float start_y = .5;
    const float step_x = .25;
    const float step_y=.06;
public:
    //Color first=Color(1.0f,.0,.0);
    //Color second=Color(.7f,.5f,.0);
    //Color third=Color(1.0f,1.0f,.0);
    //Color fourth=Color(.0,1.0f,.0);
    std::vector<Color> cols;
    std::vector<Plane> planes;
    planeCollection()
    {
        cols.push_back(Color(1.0f,.0,.0));
        cols.push_back(Color(1.0f,.5f,.0));
        cols.push_back(Color(1.0f,1.0f,.0));
        cols.push_back(Color(.0,1.0f,.0));
        //cols.push_back(Color(.5,.5,.5));
        cols.push_back(Color(.0,1.0,1.0f));
        cols.push_back(Color(.0,.0,1.0f));
        cols.push_back(Color(.5,.0,.5f));

        int color_iterator=0;
        for(int y =0;y<=15;y++)
        {
            for(int x =0;x<8;x++)//7
            {

                Plane plane = Plane(start_x+(float)x*step_x,start_y-(float)y*step_y,.125,.03,cols.at(color_iterator));
                planes.push_back(plane);
                color_iterator++;
                if(color_iterator== cols.size()) color_iterator=0;

            }
        }
    }
    void draw()
    {
        for(auto pl : planes)
        {
            pl.draw();
        }
    }
};

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
    Plane plane = Plane(-.35,.5,.125,.03,Color(1.0f,.0,.0));

    glfwSetKeyCallback(window,kbd_callback);
    glfwSetFramebufferSizeCallback(window,resize_callback);
    std::cout<<"Entering main loop"<<std::endl;
    planeCollection planes=planeCollection();
    std::vector<Plane> pl;
    pl.push_back(plane);
    std::string c;
    while(!glfwWindowShouldClose(window))
    {
        glClearColor(.0,.0,.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        if(planes.planes.size()==0)
        {
            ball.isAlive=false;
            glfwSetWindowTitle(window,"You won!");
        }
        platform.draw();
        ball.update(planes.planes,platform);
        ball.draw();
        planes.draw();
        //std::cin>>c;
        if(!ball.isAlive&&planes.planes.size()>0)
        {
            glfwSetWindowTitle(window,"Game over!");
        }
        //plane.draw();


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
