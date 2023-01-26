cmake_minimum_required(VERSION 3.23)
project(Breakout)

set(CMAKE_CXX_STANDARD 14)

set(GLEW_H /usr/local/Cellar/glew/2.2.0_1/include/GL)
set(GLFW_H /usr/local/Cellar/glfw/3.3.8/include/GLFW)
set(GLM_H /usr/local/Cellar/glm/0.9.9.8/include/glm)
set(GLAD_H /usr/local/include/glad)
set(KHR_H /usr/local/include/KHR)
include_directories(${GLEW_H} ${GLFW_H} ${GLM_H} ${GLAD_H} ${KHR_H})

# Add target link
set(GLEW_LINK /usr/local/Cellar/glew/2.2.0_1/lib/libGLEW.2.2.dylib)
set(GLFW_LINK /usr/local/Cellar/glfw/3.3.8/lib/libglfw.3.dylib)
link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})

# Execute compilation command


add_executable(Breakout glad.c main.cpp Shader.cpp gameobjects/Plane.cpp  gameobjects/Ball.cpp gameobjects/Platform.cpp gameobjects/structs.h)#

if (APPLE)
    target_link_libraries(Breakout "-framework OpenGL")
    target_link_libraries(Breakout "-framework GLUT")
endif()
