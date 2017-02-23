//
// Created by pily on 11/02/17.
//

#ifndef WPS_PIN_GENERATOR_LOGGER_H
#define WPS_PIN_GENERATOR_LOGGER_H

#include <string>

/** Plain text logger
 */
class Logger {

public:
	virtual void log(const std::string &messageError) const = 0;

	virtual void logDebug(const std::string &messageDebug) const = 0;

	virtual void logError(const std::string &messageDebug) const = 0;

	virtual ~Logger() {}

	static bool isDebugLogActive();

	static void setDebugLogActive(bool debugLogActive);

private:
	static bool debugLogActive;
};


#endif //WPS_PIN_GENERATOR_LOGGER_H
