//
// Created by pily on 11/02/17.
//

#include "Debugger.h"
#include <iostream>
#include <string>
#include "../lib/rang/include/rang.hpp"

void Debugger::log(const std::string &string) {
	std::cout << rang::style::reset << string << std::endl;
}

void Debugger::logError(const std::string &string) {
	std::cout << rang::fg::red << rang::style::bold << "ERROR: " << rang::style::reset << rang::fg::red << string
	          << rang::style::reset << std::endl;
}
