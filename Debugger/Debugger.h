//
// Created by pily on 11/02/17.
//

#ifndef WPS_PIN_GENERATOR_DEBUGGER_H
#define WPS_PIN_GENERATOR_DEBUGGER_H

#include <string>
#include <iostream>
#include "../Exceptions/NotImplementedException.h"

#include "../lib/rang/include/rang.hpp"

class Debugger {

public:
	static void log(const std::string &string) {
		std::cout << rang::style::reset << string << std::endl;
	}

	static void logError(const std::string &string) {
		std::cout << rang::fg::red << rang::style::bold << "ERROR: " << rang::style::reset << rang::fg::red << string
		          << rang::style::reset << std::endl;
	}
};


#endif //WPS_PIN_GENERATOR_DEBUGGER_H
