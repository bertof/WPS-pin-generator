//
// Created by pily on 11/02/17.
//

#ifndef WPS_PIN_GENERATOR_DEBUGGER_H
#define WPS_PIN_GENERATOR_DEBUGGER_H

#include <string>

class Debugger {

public:
	static void log(const std::string &string);

	static void logError(const std::string &string);
};


#endif //WPS_PIN_GENERATOR_DEBUGGER_H
