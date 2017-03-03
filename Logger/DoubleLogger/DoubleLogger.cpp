//
// Created by pily on 28/02/17.
//

#include "DoubleLogger.h"

DoubleLogger::DoubleLogger() {}

void DoubleLogger::log(const std::string &string) const {
	ScreenLogger::log(string);
	TextLogger::log(string);
}

void DoubleLogger::logError(const std::string &string) const {
	ScreenLogger::logError(string);
	TextLogger::logError(string);
}

void DoubleLogger::logDebug(const std::string &string) const {
	ScreenLogger::logDebug(string);
	TextLogger::logDebug(string);
}

void DoubleLogger::logVerbouse(const std::string &string) const {
	ScreenLogger::logVerbouse(string);
	TextLogger::logVerbouse(string);
}
