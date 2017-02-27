//
// Created by pily on 11/02/17.
//

#include "Generator.h"
#include "../../Exceptions/NotImplementedException.h"
#include "../../Exceptions/InvalidInputException.h"

#include <regex>
#include <stdexcept>
#include <string>
#include <math.h>

#include "../../Logger/ScreenLogger/ScreenLogger.h"
#include "../../Logger/TextLogger/TextLogger.h"

std::vector<Pin> bertof::Generator::generatePinImp(const std::string &s) const {
//	throw NotImplementedException();

	std::vector<Pin> result = std::vector<Pin>();

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

	std::string hexValue = std::regex_replace(cleanedString, std::regex(":+"), "");

	screenLog->logDebug("Hex value:\t" + hexValue);

	unsigned long intValue = std::stoul(hexValue, nullptr, 16);

	screenLog->logDebug("Int value:\t" + std::to_string(intValue));

	screenLog->logDebug(std::to_string(std::ceil(std::log10(intValue)) - 7));

	unsigned long first7Numbers = intValue / std::pow(10, std::ceil(std::log10(intValue)) - 7);

	screenLog->logDebug("First 7 numbers of the pin:\t" + std::to_string(first7Numbers));

	unsigned long pin = 10 * first7Numbers;
	unsigned long accum = 0;
	unsigned long digit;
	unsigned long checksum;

	accum = accum + 3 * ((pin / 10000000) % 10);
	accum = accum + 1 * ((pin / 1000000) % 10);
	accum = accum + 3 * ((pin / 100000) % 10);
	accum = accum + 1 * ((pin / 10000) % 10);
	accum = accum + 3 * ((pin / 1000) % 10);
	accum = accum + 1 * ((pin / 100) % 10);
	accum = accum + 3 * ((pin / 10) % 10);

	digit = accum % 10;

	checksum = (10 - digit) % 10;

	screenLog->logDebug("Accum:\t" + std::to_string(accum));
	screenLog->logDebug("Digit:\t" + std::to_string(digit));
	screenLog->logDebug("Checksum:\t" + std::to_string(checksum));

	Pin firstResult = Pin(pin + checksum);

	screenLog->logDebug("First result:\t" + firstResult.toString());

	result.push_back(firstResult);

	return result;
}

std::string bertof::Generator::author() const {
	return "bertof";
}

std::string bertof::Generator::version() const {
	return "0.0.1";
}
