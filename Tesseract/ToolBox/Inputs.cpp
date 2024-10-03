#include "Inputs.h"

Tsrt::Inputs* Tsrt::Inputs::m_instance = nullptr;

Tsrt::Inputs::Inputs(GLFWwindow* window)
{
	m_instance = this;
	std::fill(std::begin(m_instance->m_keys), std::end(m_instance->m_keys), false);
	m_instance->m_window = window;
}

void Tsrt::Inputs::InputsDestroyer()
{
	if (m_instance == this) m_instance = nullptr;
}

void Tsrt::Inputs::callBackFunction()
{
	glfwSetKeyCallback(m_instance->m_window, m_instance->keyCallBack);
    glfwSetMouseButtonCallback(m_instance->m_window, m_instance->mouseCallBack); //IMPL MOUSE CALLBACK FUNC
}


void Tsrt::Inputs::keyCallBack(GLFWwindow* window, int key, int scanCode, int action, int mode)
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

std::string Tsrt::Inputs::keyPressed()
{
    if (m_instance) {
        // Check for letters A-Z
        if (m_instance->m_keys[GLFW_KEY_A]) return "A";
        if (m_instance->m_keys[GLFW_KEY_B]) return "B";
        if (m_instance->m_keys[GLFW_KEY_C]) return "C";
        if (m_instance->m_keys[GLFW_KEY_D]) return "D";
        if (m_instance->m_keys[GLFW_KEY_E]) return "E";
        if (m_instance->m_keys[GLFW_KEY_F]) return "F";
        if (m_instance->m_keys[GLFW_KEY_G]) return "G";
        if (m_instance->m_keys[GLFW_KEY_H]) return "H";
        if (m_instance->m_keys[GLFW_KEY_I]) return "I";
        if (m_instance->m_keys[GLFW_KEY_J]) return "J";
        if (m_instance->m_keys[GLFW_KEY_K]) return "K";
        if (m_instance->m_keys[GLFW_KEY_L]) return "L";
        if (m_instance->m_keys[GLFW_KEY_M]) return "M";
        if (m_instance->m_keys[GLFW_KEY_N]) return "N";
        if (m_instance->m_keys[GLFW_KEY_O]) return "O";
        if (m_instance->m_keys[GLFW_KEY_P]) return "P";
        if (m_instance->m_keys[GLFW_KEY_Q]) return "Q";
        if (m_instance->m_keys[GLFW_KEY_R]) return "R";
        if (m_instance->m_keys[GLFW_KEY_S]) return "S";
        if (m_instance->m_keys[GLFW_KEY_T]) return "T";
        if (m_instance->m_keys[GLFW_KEY_U]) return "U";
        if (m_instance->m_keys[GLFW_KEY_V]) return "V";
        if (m_instance->m_keys[GLFW_KEY_W]) return "W";
        if (m_instance->m_keys[GLFW_KEY_X]) return "X";
        if (m_instance->m_keys[GLFW_KEY_Y]) return "Y";
        if (m_instance->m_keys[GLFW_KEY_Z]) return "Z";

        // Check for numbers 0-9
        if (m_instance->m_keys[GLFW_KEY_0]) return "0";
        if (m_instance->m_keys[GLFW_KEY_1]) return "1";
        if (m_instance->m_keys[GLFW_KEY_2]) return "2";
        if (m_instance->m_keys[GLFW_KEY_3]) return "3";
        if (m_instance->m_keys[GLFW_KEY_4]) return "4";
        if (m_instance->m_keys[GLFW_KEY_5]) return "5";
        if (m_instance->m_keys[GLFW_KEY_6]) return "6";
        if (m_instance->m_keys[GLFW_KEY_7]) return "7";
        if (m_instance->m_keys[GLFW_KEY_8]) return "8";
        if (m_instance->m_keys[GLFW_KEY_9]) return "9";

        // Check for function keys F1-F12
        if (m_instance->m_keys[GLFW_KEY_F1]) return "F1";
        if (m_instance->m_keys[GLFW_KEY_F2]) return "F2";
        if (m_instance->m_keys[GLFW_KEY_F3]) return "F3";
        if (m_instance->m_keys[GLFW_KEY_F4]) return "F4";
        if (m_instance->m_keys[GLFW_KEY_F5]) return "F5";
        if (m_instance->m_keys[GLFW_KEY_F6]) return "F6";
        if (m_instance->m_keys[GLFW_KEY_F7]) return "F7";
        if (m_instance->m_keys[GLFW_KEY_F8]) return "F8";
        if (m_instance->m_keys[GLFW_KEY_F9]) return "F9";
        if (m_instance->m_keys[GLFW_KEY_F10]) return "F10";
        if (m_instance->m_keys[GLFW_KEY_F11]) return "F11";
        if (m_instance->m_keys[GLFW_KEY_F12]) return "F12";

        // Check for common special keys
        if (m_instance->m_keys[GLFW_KEY_SPACE]) return "Space";
        if (m_instance->m_keys[GLFW_KEY_ENTER]) return "Enter";
        if (m_instance->m_keys[GLFW_KEY_BACKSPACE]) return "Backspace";
        if (m_instance->m_keys[GLFW_KEY_TAB]) return "Tab";
        if (m_instance->m_keys[GLFW_KEY_ESCAPE]) return "Escape";
        if (m_instance->m_keys[GLFW_KEY_LEFT_SHIFT] || m_instance->m_keys[GLFW_KEY_RIGHT_SHIFT]) return "Shift";
        if (m_instance->m_keys[GLFW_KEY_LEFT_CONTROL] || m_instance->m_keys[GLFW_KEY_RIGHT_CONTROL]) return "Control";
        if (m_instance->m_keys[GLFW_KEY_LEFT_ALT] || m_instance->m_keys[GLFW_KEY_RIGHT_ALT]) return "Alt";

        // Check for arrow keys
        if (m_instance->m_keys[GLFW_KEY_LEFT]) return "Left Arrow";
        if (m_instance->m_keys[GLFW_KEY_RIGHT]) return "Right Arrow";
        if (m_instance->m_keys[GLFW_KEY_UP]) return "Up Arrow";
        if (m_instance->m_keys[GLFW_KEY_DOWN]) return "Down Arrow";

        // Check for punctuation and other symbols
        if (m_instance->m_keys[GLFW_KEY_COMMA]) return ",";
        if (m_instance->m_keys[GLFW_KEY_PERIOD]) return ".";
        if (m_instance->m_keys[GLFW_KEY_SLASH]) return "/";
        if (m_instance->m_keys[GLFW_KEY_SEMICOLON]) return ";";
        if (m_instance->m_keys[GLFW_KEY_APOSTROPHE]) return "'";
        if (m_instance->m_keys[GLFW_KEY_LEFT_BRACKET]) return "[";
        if (m_instance->m_keys[GLFW_KEY_RIGHT_BRACKET]) return "]";
        if (m_instance->m_keys[GLFW_KEY_MINUS]) return "-";
        if (m_instance->m_keys[GLFW_KEY_EQUAL]) return "=";
        if (m_instance->m_keys[GLFW_KEY_BACKSLASH]) return "\\";
        if (m_instance->m_keys[GLFW_KEY_GRAVE_ACCENT]) return "`";

        // Check for other useful keys
        if (m_instance->m_keys[GLFW_KEY_INSERT]) return "Insert";
        if (m_instance->m_keys[GLFW_KEY_DELETE]) return "Delete";
        if (m_instance->m_keys[GLFW_KEY_HOME]) return "Home";
        if (m_instance->m_keys[GLFW_KEY_END]) return "End";
        if (m_instance->m_keys[GLFW_KEY_PAGE_UP]) return "Page Up";
        if (m_instance->m_keys[GLFW_KEY_PAGE_DOWN]) return "Page Down";

        // Keypad keys
        if (m_instance->m_keys[GLFW_KEY_KP_0]) return "Keypad 0";
        if (m_instance->m_keys[GLFW_KEY_KP_1]) return "Keypad 1";
        if (m_instance->m_keys[GLFW_KEY_KP_2]) return "Keypad 2";
        if (m_instance->m_keys[GLFW_KEY_KP_3]) return "Keypad 3";
        if (m_instance->m_keys[GLFW_KEY_KP_4]) return "Keypad 4";
        if (m_instance->m_keys[GLFW_KEY_KP_5]) return "Keypad 5";
        if (m_instance->m_keys[GLFW_KEY_KP_6]) return "Keypad 6";
        if (m_instance->m_keys[GLFW_KEY_KP_7]) return "Keypad 7";
        if (m_instance->m_keys[GLFW_KEY_KP_8]) return "Keypad 8";
        if (m_instance->m_keys[GLFW_KEY_KP_9]) return "Keypad 9";
        if (m_instance->m_keys[GLFW_KEY_KP_ADD]) return "Keypad +";
        if (m_instance->m_keys[GLFW_KEY_KP_SUBTRACT]) return "Keypad -";
        if (m_instance->m_keys[GLFW_KEY_KP_MULTIPLY]) return "Keypad *";
        if (m_instance->m_keys[GLFW_KEY_KP_DIVIDE]) return "Keypad /";
        if (m_instance->m_keys[GLFW_KEY_KP_ENTER]) return "Keypad Enter";

        // Media and other keys
        if (m_instance->m_keys[GLFW_KEY_PRINT_SCREEN]) return "Print Screen";
        if (m_instance->m_keys[GLFW_KEY_PAUSE]) return "Pause";
    }
    return ""; // If no key is pressed, return an empty string

}