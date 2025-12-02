#include "KeyboardReader.h"

KeyboardReader::KeyboardReader()
{
	if (textScancodes.empty()) {
        // letters
        textScancodes.insert_or_assign(graphics::SCANCODE_A, 'a');
        textScancodes.insert_or_assign(graphics::SCANCODE_B, 'b');
        textScancodes.insert_or_assign(graphics::SCANCODE_C, 'c');
        textScancodes.insert_or_assign(graphics::SCANCODE_D, 'd');
        textScancodes.insert_or_assign(graphics::SCANCODE_E, 'e');
        textScancodes.insert_or_assign(graphics::SCANCODE_F, 'f');
        textScancodes.insert_or_assign(graphics::SCANCODE_G, 'g');
        textScancodes.insert_or_assign(graphics::SCANCODE_H, 'h');
        textScancodes.insert_or_assign(graphics::SCANCODE_I, 'i');
        textScancodes.insert_or_assign(graphics::SCANCODE_J, 'j');
        textScancodes.insert_or_assign(graphics::SCANCODE_K, 'k');
        textScancodes.insert_or_assign(graphics::SCANCODE_L, 'l');
        textScancodes.insert_or_assign(graphics::SCANCODE_M, 'm');
        textScancodes.insert_or_assign(graphics::SCANCODE_N, 'n');
        textScancodes.insert_or_assign(graphics::SCANCODE_O, 'o');
        textScancodes.insert_or_assign(graphics::SCANCODE_P, 'p');
        textScancodes.insert_or_assign(graphics::SCANCODE_Q, 'q');
        textScancodes.insert_or_assign(graphics::SCANCODE_R, 'r');
        textScancodes.insert_or_assign(graphics::SCANCODE_S, 's');
        textScancodes.insert_or_assign(graphics::SCANCODE_T, 't');
        textScancodes.insert_or_assign(graphics::SCANCODE_U, 'u');
        textScancodes.insert_or_assign(graphics::SCANCODE_V, 'v');
        textScancodes.insert_or_assign(graphics::SCANCODE_W, 'w');
        textScancodes.insert_or_assign(graphics::SCANCODE_X, 'x');
        textScancodes.insert_or_assign(graphics::SCANCODE_Y, 'y');
        textScancodes.insert_or_assign(graphics::SCANCODE_Z, 'z');
                     
        // numbers
        textScancodes.insert_or_assign(graphics::SCANCODE_1, '1');
        textScancodes.insert_or_assign(graphics::SCANCODE_2, '2');
        textScancodes.insert_or_assign(graphics::SCANCODE_3, '3');
        textScancodes.insert_or_assign(graphics::SCANCODE_4, '4');
        textScancodes.insert_or_assign(graphics::SCANCODE_5, '5');
        textScancodes.insert_or_assign(graphics::SCANCODE_6, '6');
        textScancodes.insert_or_assign(graphics::SCANCODE_7, '7');
        textScancodes.insert_or_assign(graphics::SCANCODE_8, '8');
        textScancodes.insert_or_assign(graphics::SCANCODE_9, '9');
        textScancodes.insert_or_assign(graphics::SCANCODE_0, '0');

        // space & common symbols
        textScancodes.insert_or_assign(graphics::SCANCODE_SPACE, ' ');
        textScancodes.insert_or_assign(graphics::SCANCODE_MINUS, '-');
        textScancodes.insert_or_assign(graphics::SCANCODE_EQUALS, '=');
        textScancodes.insert_or_assign(graphics::SCANCODE_LEFTBRACKET, '[');
        textScancodes.insert_or_assign(graphics::SCANCODE_RIGHTBRACKET, ']');
        textScancodes.insert_or_assign(graphics::SCANCODE_BACKSLASH, '\\');
        textScancodes.insert_or_assign(graphics::SCANCODE_SEMICOLON, ';');
        textScancodes.insert_or_assign(graphics::SCANCODE_APOSTROPHE, '\'');
        textScancodes.insert_or_assign(graphics::SCANCODE_GRAVE, '`');
        textScancodes.insert_or_assign(graphics::SCANCODE_COMMA, ',');
        textScancodes.insert_or_assign(graphics::SCANCODE_PERIOD, '.');
        textScancodes.insert_or_assign(graphics::SCANCODE_SLASH, '/');
        textScancodes.insert_or_assign(graphics::SCANCODE_BACKSPACE, 42);
	}
}

KeyboardReader::~KeyboardReader() {
    std::map<graphics::scancode_t, char>().swap(textScancodes);
}

char KeyboardReader::getKeyPressed()
{
    std::map<graphics::scancode_t, char>::iterator it = textScancodes.begin();
    
    while (it != textScancodes.end()) {
        if (graphics::getKeyState(it->first))
            return it->second;
        
        it++;
    }

    return '\0';
}
