#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <algorithm>

namespace TsrtInputs
{
    class InputHandler
    {
    public:
        explicit InputHandler(GLFWwindow* window);
        ~InputHandler();

        void initializeCallbacks();
        const char* keyPressed() const;

        static InputHandler* getInstance() { return instance; }

    private:
        bool keys[1024]{};
        GLFWwindow* window;

        static InputHandler* instance;

        static void keyboardListener(GLFWwindow* window, int key, int scancode, int action, int mode);
    };
}
