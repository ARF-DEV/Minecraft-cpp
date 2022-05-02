
#include "InputEvent.h"

bool InputEvent::keyboard_was_pressed = false;
bool InputEvent::mouse_was_pressed = false;

int InputEvent::keyboard_key = 0;
int InputEvent::keyboard_scancode = 0;
int InputEvent::keyboard_action = 0;
int InputEvent::keyboard_mods = 0;
int InputEvent::mouse_button = 0;
int InputEvent::mouse_action = 0;
int InputEvent::mouse_mods = 0;

void InputEvent::keyboardCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
     
     if (action == GLFW_PRESS) {
          InputEvent::keyboard_action = action;
          InputEvent::keyboard_key = key;
          InputEvent::keyboard_mods = mods;
          InputEvent::keyboard_scancode = scancode;
     } else {
          InputEvent::keyboard_action = 0;
          InputEvent::keyboard_key = 0;
          InputEvent::keyboard_mods = 0;
          InputEvent::keyboard_scancode = 0;
          InputEvent::keyboard_was_pressed = false;
     }
}

bool InputEvent::KeyIsPressed(int key) {
     if (keyboard_was_pressed || keyboard_action != GLFW_PRESS) {
          return false;
     }
     keyboard_was_pressed = true;
     return key == keyboard_key;
}

void InputEvent::mouseCallback(GLFWwindow* window, int button, int action, int mods) {
     if (action == GLFW_PRESS) {
          InputEvent::mouse_action = action;
          InputEvent::mouse_button = button;
          InputEvent::mouse_mods = mods;
     } else {
          InputEvent::mouse_action = 0;
          InputEvent::mouse_button = 0;
          InputEvent::mouse_mods = 0;
          InputEvent::mouse_was_pressed = false;
     }

}

bool InputEvent::MouseButtonIsPressed(int button) {
     if (mouse_was_pressed || mouse_action != GLFW_PRESS) {
          return false;
     }
     mouse_was_pressed = true;
     return button == mouse_button;
}

InputEvent::InputEvent(GLFWwindow* window) 
{
     glfwSetKeyCallback(window, InputEvent::keyboardCallback);
     glfwSetMouseButtonCallback(window, InputEvent::mouseCallback);
}