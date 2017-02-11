//
// Created by pily on 11/02/17.
//

#include "Debugger.h"
#include <ostream>
#include <string>
#include "../lib/rang/include/rang.hpp"

void Debugger::log(const std::string &string) {
	if (isDebugActive()) {
		std::cout << rang::style::reset << string << std::endl;
	}
}

void Debugger::logError(const std::string &string) {
	if (isDebugActive()) {
		std::cout << rang::fg::red << "ERROR" << rang::style::reset << ": " << rang::fg::red
		          << string
		          << rang::style::reset << std::endl;
	}
}

void Debugger::logDebug(const std::string &string) {
	if (isDebugActive()) {
		std::cout << rang::fg::cyan << "DEBUG" << rang::style::reset << ": " << string
		          << std::endl;
	}
}

bool Debugger::isDebugActive() {
	return Debugger::debugActivityStatus;
}

bool Debugger::toggleDebugActivityStatus(const bool &status) {
	Debugger::debugActivityStatus = status;
	return Debugger::debugActivityStatus;
}

bool Debugger::debugActivityStatus = false;