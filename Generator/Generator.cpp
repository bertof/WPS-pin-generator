//
// Created by pily on 11/02/17.
//

#include "Generator.h"
#include "../Exceptions/NotImplementedException.h"
#include "../Exceptions/InvalidInputException.h"

#include <regex>
#include <stdexcept>
#include <string>

#include "../Logger/ScreenLogger/ScreenLogger.h"
#include "../Logger/TextLogger/TextLogger.h"

std::vector<Pin> Generator::generatePinImp(const std::string &s) const {
//	throw NotImplementedException();

	Logger *screenLog = new ScreenLogger();
	Logger *fileLog = new TextLogger();

	std::string stringPassed = std::string(s);

	screenLog->logDebug("String passed:\t" + stringPassed);
	fileLog->logDebug("String passed:\t" + stringPassed);

	// Cleaning input string, only hexadecimal characters allowed
	std::string cleanedString = std::regex_replace(stringPassed, std::regex("[^0-9A-F]:"), "");

	screenLog->logDebug("Cleaned string:\t" + cleanedString);
	fileLog->logDebug("Cleaned string:\t" + cleanedString);

	// Check if length is valid
	if (cleanedString.length() != 12 + 5) {
		screenLog->logError("The string passed is not a valid MAC address");
		fileLog->logError("The string passed is not a valid MAC address");
		throw InvalidInputException("The string passed is not a valid MAC address");
	}


	return std::vector<Pin>();
}

std::string Generator::author() const {
	return "bertof";
}

std::string Generator::version() const {
	return "0.0.1";
}
