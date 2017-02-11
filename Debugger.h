//
// Created by pily on 11/02/17.
//

#ifndef WPS_PIN_GENERATOR_DEBUGGER_H
#define WPS_PIN_GENERATOR_DEBUGGER_H

#include <string>
#include <iostream>
#include "Exceptions/NotImplementedException.h"

#include "lib/rang/include/rang.hpp"

class Debugger {

public:
	static void log(const std::string &string) {
		throw NotImplementedException();
	}

	static void logError(const std::string &string) {
		throw NotImplementedException();
	}

	static void testColors() {
		std::cout << rang::bg::blue << rang::fg::red << "Test" << rang::style::reset << std::endl;

	}
};


#endif //WPS_PIN_GENERATOR_DEBUGGER_H
