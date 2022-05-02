#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>

class InputEvent
{
private:
     static void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
     static void mouseCallback(GLFWwindow* window, int key, int action, int mods);
public:
     // void Init(GLFWwindow* window);
     InputEvent(GLFWwindow* window);
     bool KeyIsPressed(int key);
     bool KeyIsDown(int key);
     // bool keyIsRelease(int key);
     bool MouseButtonIsPressed(int button);
     bool MouseButtonIsDown(int button);
     // bool mouseButtonRelease(int)
private:
     // GLFWwindow* window;
     static int keyboard_key, keyboard_prev_action, keyboard_scancode, keyboard_action, keyboard_mods;
     static bool keyboard_was_pressed;
     static int mouse_button, mouse_prev_button ,mouse_action, mouse_mods;
     static bool mouse_was_pressed;
};