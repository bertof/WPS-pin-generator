//
// Created by pily on 01/03/17.
//

#ifndef WPS_PIN_GENERATOR_INPUTHANDLER_H
#define WPS_PIN_GENERATOR_INPUTHANDLER_H

#include <string>
#include <vector>

class InputHandler {
private:
	static std::string bssidInput;
public:
	static void handle(int argc, char *argv[]);

	static const std::string &getBssidInput();

	static void setBssidInput(const std::string &bssidInput);
};

#endif //WPS_PIN_GENERATOR_INPUTHANDLER_H
