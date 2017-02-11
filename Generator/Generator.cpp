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

std::vector<Pin> Generator::generatePinImp(const std::string &s) const {
//	throw NotImplementedException();

	Logger *log = new ScreenLogger();

	std::string stringPassed = std::string(s);

	log->logDebug("String passed:\t" + stringPassed);

	// Cleaning input string, only hexadecimal characters allowed
	std::string cleanedString = std::regex_replace(stringPassed, std::regex("[^0-9A-F]:"), "");

	log->logDebug("Cleaned string:\t" + cleanedString);

	// Check if length is valid
	if (cleanedString.length() != 12 + 5) {
		log->logError("The string passed is not a valid MAC address");
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
