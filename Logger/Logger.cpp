//
// Created by pily on 11/02/17.
//

#include "Logger.h"

bool Logger::debugLogActive = false;

bool Logger::verbouseLogActive = false;

bool Logger::isDebugLogActive() {
	return debugLogActive;
}

void Logger::setDebugLogActive(bool debugLogActive) {
	Logger::debugLogActive = debugLogActive;
}

bool Logger::isVerbouseLogActive() {
	return verbouseLogActive;
}

void Logger::setVerbouseLogActive(bool verbouseLogActive) {
	Logger::verbouseLogActive = verbouseLogActive;
}