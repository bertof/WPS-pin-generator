//
// Created by pily on 11/02/17.
//

#include "Logger.h"

bool Logger::debugLogActive = false;

bool Logger::isDebugLogActive() {
	return debugLogActive;
}

void Logger::setDebugLogActive(bool debugLogActive) {
	Logger::debugLogActive = debugLogActive;
}
