#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <cstdio>

#include "src/InputEvent.h"

bool FullScreenMode = false;
constexpr int windowHeight = 300;
constexpr int windowWidth = 600;
const char* windowTitle = "Minecraft";


int main () {
    if(!glfwInit()) {
        printf("Failed to initilized window\n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* monitorMode = glfwGetVideoMode(monitor);

    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);

    if (window == nullptr) {
        printf("Failed to initialize window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, windowWidth, windowHeight);

    InputEvent input(window);

    while(!glfwWindowShouldClose(window)) {

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        const bool prevFullScreenMode = FullScreenMode;

        if (input.KeyIsPressed(GLFW_KEY_SPACE)) {
            FullScreenMode = !FullScreenMode;
        }

        if (input.MouseButtonIsPressed(GLFW_MOUSE_BUTTON_LEFT)) {
            FullScreenMode = !FullScreenMode;
        }

        if (prevFullScreenMode != FullScreenMode) {
            if (FullScreenMode) {
                glfwSetWindowMonitor(
                    window, 
                    monitor, 
                    0, 
                    0, 
                    monitorMode->width, 
                    monitorMode->height, 
                    monitorMode->refreshRate
                );
            } else {
                glfwSetWindowMonitor(
                    window, 
                    NULL, 
                    monitorMode->width/2 - windowWidth/2, 
                    monitorMode->height/2 - windowHeight/2, 
                    windowWidth,
                    windowHeight,
                    monitorMode->refreshRate
                );
            }
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

}