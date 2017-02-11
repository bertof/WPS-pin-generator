//
// Created by pily on 11/02/17.
//

#include "ScreenLogger.h"
#include "../../lib/rang/include/rang.hpp"
#include <ostream>
#include <string>

void ScreenLogger::log(const std::string &string) {
	std::cout << rang::style::reset << string << std::endl;
}

void ScreenLogger::logError(const std::string &string) {
	std::cout << rang::fg::red << "ERROR" << rang::style::reset << ": " << rang::fg::red
	          << string
	          << rang::style::reset << std::endl;

}

void ScreenLogger::logDebug(const std::string &string) {
	if (Logger::isDebugLogActive()) {
		std::cout << rang::fg::cyan << "DEBUG" << rang::style::reset << ": " << string
		          << std::endl;
	}
}