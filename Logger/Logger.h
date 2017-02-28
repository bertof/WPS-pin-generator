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
	virtual void log(const std::string &messageLog) const = 0;

	virtual void logVerbouse(const std::string &messageLogVerbouse) const = 0;

	virtual void logDebug(const std::string &messageDebug) const = 0;

	virtual void logError(const std::string &messageError) const = 0;

	virtual ~Logger() {}

	static bool isDebugLogActive();

	static void setDebugLogActive(bool debugLogActive);
private:
	static bool debugLogActive;

	static bool verbouseLogActive;
public:
	static bool isVerbouseLogActive();

	static void setVerbouseLogActive(bool verbouseLogActive);
};


#endif //WPS_PIN_GENERATOR_LOGGER_H
