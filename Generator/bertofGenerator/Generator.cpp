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

#include "../../Logger/DoubleLogger/DoubleLogger.h"

std::vector<Pin> bertof::Generator::generatePinImp(const std::string &s) const {

	std::vector<Pin> result = std::vector<Pin>();

	std::shared_ptr<DoubleLogger> logger(DoubleLogger::getDoubleLogger());

	logger->logVerbouse("Starting bertofGenerator");

	std::string stringPassed = std::string(s);

	logger->logDebug("String passed:\t" + stringPassed);

	// Cleaning input string, only hexadecimal characters allowed
	std::string cleanedString = std::regex_replace(stringPassed, std::regex("[^0-9A-F]:"), "");

	logger->logDebug("Cleaned string:\t" + cleanedString);

	// Check if length is valid
	if (cleanedString.length() != 12 + 5) {
		logger->logError("The string passed is not a valid MAC address");
		throw InvalidInputException("The string passed is not a valid MAC address");
	}

	std::string hexValue = std::regex_replace(cleanedString, std::regex(":+"), "");

	logger->logDebug("Hex value:\t" + hexValue);

	std::string lastHalfHexValue = hexValue.substr(6, 6);

	logger->logDebug("Last half hex value:\t" + lastHalfHexValue);

	unsigned long intValue = std::stoul(lastHalfHexValue, nullptr, 16);

	logger->logDebug("Int value:\t" + std::to_string(intValue));

	unsigned long zaoModeIntValue = intValue % 10000000;

	logger->logDebug("Zao Mode integer value=\t" + std::to_string(zaoModeIntValue));

	unsigned long first7Numbers = zaoModeIntValue / std::pow(10, std::ceil(std::log10(zaoModeIntValue)) - 7);

	logger->logDebug("First 7 numbers of the pin:\t" + std::to_string(first7Numbers));

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

	logger->logDebug("Accum:\t" + std::to_string(accum));
	logger->logDebug("Digit:\t" + std::to_string(digit));
	logger->logDebug("Checksum:\t" + std::to_string(checksum));

	Pin firstResult = Pin(pin + checksum);

	logger->logVerbouse("End of bertofGenerator");
	logger->logVerbouse("First result:\t" + firstResult.toString());

	result.push_back(firstResult);

	return result;
}

std::string bertof::Generator::author() const {
	return "bertof";
}

std::string bertof::Generator::version() const {
	return "0.0.1";
}
