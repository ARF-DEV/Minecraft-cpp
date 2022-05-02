#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <cstdio>

#include "src/InputEvent.h"

bool FullScreenMode = false;

int main () {
    if(!glfwInit()) {
        printf("Failed to initilized window\n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    const int windowHeight = 300;
    const int windowWidth = 600;

    const char* windowTitle = "Minecraft";

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

        if (input.KeyIsPressed(GLFW_KEY_SPACE)) {
            printf("TEHEEE\n");
        }

        if (input.MouseButtonIsPressed(GLFW_MOUSE_BUTTON_LEFT)) {
            printf("YOHOOO\n");
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

}