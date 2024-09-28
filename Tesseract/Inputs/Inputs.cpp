#include "Inputs.h"

namespace TsrtInputs
{
    InputHandler* InputHandler::instance = nullptr;

    InputHandler::InputHandler(GLFWwindow* window) : window(window)
    {
        if (instance)
        {
            std::cerr << "InputHandler instance already exists! Only one instance is allowed." << std::endl;
            throw std::runtime_error("Multiple InputHandler instances are not allowed.");
        }
        instance = this;
        std::fill(std::begin(keys), std::end(keys), false);
    }

    InputHandler::~InputHandler()
    {
        if (instance == this)
            instance = nullptr;
    }

    void InputHandler::initializeCallbacks()
    {
        if (window)
        {
            glfwSetKeyCallback(window, keyboardListener);
        }
        else
        {
            std::cerr << "GLFW window is not set, cannot initialize input callbacks." << std::endl;
        }
    }

    const char* InputHandler::keyPressed() const
    {
        if (!instance) return "";

        // Check common keys, returning the first match.
        for (int key = 0; key < 1024; ++key)
        {
            if (instance->keys[key])
            {
                switch (key)
                {
                case GLFW_KEY_A: return "A";
                case GLFW_KEY_B: return "B";
                case GLFW_KEY_C: return "C";
                case GLFW_KEY_D: return "D";
                case GLFW_KEY_E: return "E";
                case GLFW_KEY_F: return "F";
                case GLFW_KEY_G: return "G";
                case GLFW_KEY_H: return "H";
                case GLFW_KEY_I: return "I";
                case GLFW_KEY_J: return "J";
                case GLFW_KEY_K: return "K";
                case GLFW_KEY_L: return "L";
                case GLFW_KEY_M: return "M";
                case GLFW_KEY_N: return "N";
                case GLFW_KEY_O: return "O";
                case GLFW_KEY_P: return "P";
                case GLFW_KEY_Q: return "Q";
                case GLFW_KEY_R: return "R";
                case GLFW_KEY_S: return "S";
                case GLFW_KEY_T: return "T";
                case GLFW_KEY_U: return "U";
                case GLFW_KEY_V: return "V";
                case GLFW_KEY_W: return "W";
                case GLFW_KEY_X: return "X";
                case GLFW_KEY_Y: return "Y";
                case GLFW_KEY_Z: return "Z";
                case GLFW_KEY_0: return "0";
                case GLFW_KEY_1: return "1";
                case GLFW_KEY_2: return "2";
                case GLFW_KEY_3: return "3";
                case GLFW_KEY_4: return "4";
                case GLFW_KEY_5: return "5";
                case GLFW_KEY_6: return "6";
                case GLFW_KEY_7: return "7";
                case GLFW_KEY_8: return "8";
                case GLFW_KEY_9: return "9";
                case GLFW_KEY_SPACE: return "SPACE";
                case GLFW_KEY_ENTER: return "ENTER";
                case GLFW_KEY_ESCAPE: return "ESCAPE";
                case GLFW_KEY_TAB: return "TAB";
                case GLFW_KEY_LEFT: return "LEFT ARROW";
                case GLFW_KEY_RIGHT: return "RIGHT ARROW";
                case GLFW_KEY_UP: return "UP ARROW";
                case GLFW_KEY_DOWN: return "DOWN ARROW";
                    // Add more keys as needed...
                default: break;
                }
            }
        }

        return "";
    }


    void InputHandler::keyboardListener(GLFWwindow* window, int key, int scancode, int action, int mode)
    {
        if (instance)
        {
            if (key >= 0 && key < 1024)
            {
                instance->keys[key] = (action == GLFW_PRESS || action == GLFW_REPEAT);
            }
        }
    }
}
