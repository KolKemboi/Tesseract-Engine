#include "Inputs.h"

//----------------------------MOUSE INPUTS ---------------------------------------------

Tsrt::KeyboardInputs* Tsrt::KeyboardInputs::m_instance = nullptr;

Tsrt::KeyboardInputs::KeyboardInputs(GLFWwindow* window)
{
	m_instance = this;
	std::fill(std::begin(m_instance->m_keys), std::end(m_instance->m_keys), false);
	m_instance->m_window = window;
}

void Tsrt::KeyboardInputs::KeyboardInputsDestroyer()
{
	if (m_instance == this) m_instance = nullptr;
}

void Tsrt::KeyboardInputs::callBackFunction()
{
	glfwSetKeyCallback(m_instance->m_window, m_instance->keyCallBack);

}


void Tsrt::KeyboardInputs::keyCallBack(GLFWwindow* window, int key, int scanCode, int action, int mode)
{
	if (m_instance)
	{
		if (key >= 0 && key < 1024)
		{
			if (action == GLFW_PRESS) m_instance->m_keys[key] = true;
			else if (action == GLFW_RELEASE) m_instance->m_keys[key] = false;

		}
	}
}

std::string Tsrt::KeyboardInputs::keyPressed()
{
    std::string pressedKeys = "";

    if (m_instance) {
        // Check for letters A-Z
        if (m_instance->m_keys[GLFW_KEY_A]) pressedKeys += " A ";
        if (m_instance->m_keys[GLFW_KEY_B]) pressedKeys += " B ";
        if (m_instance->m_keys[GLFW_KEY_C]) pressedKeys += " C ";
        if (m_instance->m_keys[GLFW_KEY_D]) pressedKeys += " D ";
        if (m_instance->m_keys[GLFW_KEY_E]) pressedKeys += " E ";
        if (m_instance->m_keys[GLFW_KEY_F]) pressedKeys += " F ";
        if (m_instance->m_keys[GLFW_KEY_G]) pressedKeys += " G ";
        if (m_instance->m_keys[GLFW_KEY_H]) pressedKeys += " H ";
        if (m_instance->m_keys[GLFW_KEY_I]) pressedKeys += " I ";
        if (m_instance->m_keys[GLFW_KEY_J]) pressedKeys += " J ";
        if (m_instance->m_keys[GLFW_KEY_K]) pressedKeys += " K ";
        if (m_instance->m_keys[GLFW_KEY_L]) pressedKeys += " L ";
        if (m_instance->m_keys[GLFW_KEY_M]) pressedKeys += " M ";
        if (m_instance->m_keys[GLFW_KEY_N]) pressedKeys += " N ";
        if (m_instance->m_keys[GLFW_KEY_O]) pressedKeys += " O ";
        if (m_instance->m_keys[GLFW_KEY_P]) pressedKeys += " P ";
        if (m_instance->m_keys[GLFW_KEY_Q]) pressedKeys += " Q ";
        if (m_instance->m_keys[GLFW_KEY_R]) pressedKeys += " R ";
        if (m_instance->m_keys[GLFW_KEY_S]) pressedKeys += " S ";
        if (m_instance->m_keys[GLFW_KEY_T]) pressedKeys += " T ";
        if (m_instance->m_keys[GLFW_KEY_U]) pressedKeys += " U ";
        if (m_instance->m_keys[GLFW_KEY_V]) pressedKeys += " V ";
        if (m_instance->m_keys[GLFW_KEY_W]) pressedKeys += " W ";
        if (m_instance->m_keys[GLFW_KEY_X]) pressedKeys += " X ";
        if (m_instance->m_keys[GLFW_KEY_Y]) pressedKeys += " Y ";
        if (m_instance->m_keys[GLFW_KEY_Z]) pressedKeys += " Z ";

        // Check for numbers 0-9
        if (m_instance->m_keys[GLFW_KEY_0]) pressedKeys += " 0 ";
        if (m_instance->m_keys[GLFW_KEY_1]) pressedKeys += " 1 ";
        if (m_instance->m_keys[GLFW_KEY_2]) pressedKeys += " 2 ";
        if (m_instance->m_keys[GLFW_KEY_3]) pressedKeys += " 3 ";
        if (m_instance->m_keys[GLFW_KEY_4]) pressedKeys += " 4 ";
        if (m_instance->m_keys[GLFW_KEY_5]) pressedKeys += " 5 ";
        if (m_instance->m_keys[GLFW_KEY_6]) pressedKeys += " 6 ";
        if (m_instance->m_keys[GLFW_KEY_7]) pressedKeys += " 7 ";
        if (m_instance->m_keys[GLFW_KEY_8]) pressedKeys += " 8 ";
        if (m_instance->m_keys[GLFW_KEY_9]) pressedKeys += " 9 ";

        // Function keys
        if (m_instance->m_keys[GLFW_KEY_F1]) pressedKeys += " F1 ";
        if (m_instance->m_keys[GLFW_KEY_F2]) pressedKeys += " F2 ";
        if (m_instance->m_keys[GLFW_KEY_F3]) pressedKeys += " F3 ";
        if (m_instance->m_keys[GLFW_KEY_F4]) pressedKeys += " F4 ";
        if (m_instance->m_keys[GLFW_KEY_F5]) pressedKeys += " F5 ";
        if (m_instance->m_keys[GLFW_KEY_F6]) pressedKeys += " F6 ";
        if (m_instance->m_keys[GLFW_KEY_F7]) pressedKeys += " F7 ";
        if (m_instance->m_keys[GLFW_KEY_F8]) pressedKeys += " F8 ";
        if (m_instance->m_keys[GLFW_KEY_F9]) pressedKeys += " F9 ";
        if (m_instance->m_keys[GLFW_KEY_F10]) pressedKeys += " F10 ";
        if (m_instance->m_keys[GLFW_KEY_F11]) pressedKeys += " F11 ";
        if (m_instance->m_keys[GLFW_KEY_F12]) pressedKeys += " F12 ";

        // Special keys and arrows
        if (m_instance->m_keys[GLFW_KEY_SPACE]) pressedKeys += " Space ";
        if (m_instance->m_keys[GLFW_KEY_ENTER]) pressedKeys += " Enter ";
        if (m_instance->m_keys[GLFW_KEY_BACKSPACE]) pressedKeys += " Backspace ";
        if (m_instance->m_keys[GLFW_KEY_TAB]) pressedKeys += " Tab ";
        if (m_instance->m_keys[GLFW_KEY_ESCAPE]) pressedKeys += " Escape ";
        if (m_instance->m_keys[GLFW_KEY_LEFT_SHIFT] || m_instance->m_keys[GLFW_KEY_RIGHT_SHIFT]) pressedKeys += " Shift ";
        if (m_instance->m_keys[GLFW_KEY_LEFT_CONTROL] || m_instance->m_keys[GLFW_KEY_RIGHT_CONTROL]) pressedKeys += " Control ";
        if (m_instance->m_keys[GLFW_KEY_LEFT_ALT] || m_instance->m_keys[GLFW_KEY_RIGHT_ALT]) pressedKeys += " Alt ";
        if (m_instance->m_keys[GLFW_KEY_LEFT]) pressedKeys += " Left Arrow ";
        if (m_instance->m_keys[GLFW_KEY_RIGHT]) pressedKeys += " Right Arrow ";
        if (m_instance->m_keys[GLFW_KEY_UP]) pressedKeys += " Up Arrow ";
        if (m_instance->m_keys[GLFW_KEY_DOWN]) pressedKeys += " Down Arrow ";

        // Symbols and other keys
        if (m_instance->m_keys[GLFW_KEY_COMMA]) pressedKeys += " , ";
        if (m_instance->m_keys[GLFW_KEY_PERIOD]) pressedKeys += " . ";
        if (m_instance->m_keys[GLFW_KEY_SLASH]) pressedKeys += " / ";
        if (m_instance->m_keys[GLFW_KEY_SEMICOLON]) pressedKeys += " ; ";
        if (m_instance->m_keys[GLFW_KEY_APOSTROPHE]) pressedKeys += " ' ";
        if (m_instance->m_keys[GLFW_KEY_LEFT_BRACKET]) pressedKeys += " [ ";
        if (m_instance->m_keys[GLFW_KEY_RIGHT_BRACKET]) pressedKeys += " ] ";
        if (m_instance->m_keys[GLFW_KEY_MINUS]) pressedKeys += " - ";
        if (m_instance->m_keys[GLFW_KEY_EQUAL]) pressedKeys += " = ";
        if (m_instance->m_keys[GLFW_KEY_BACKSLASH]) pressedKeys += " \\ ";
        if (m_instance->m_keys[GLFW_KEY_GRAVE_ACCENT]) pressedKeys += " ` ";
    }

    return pressedKeys.empty() ? "None" : pressedKeys;
}