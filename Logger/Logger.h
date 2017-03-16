//
// Created by pily on 11/02/17.
//

#ifndef WPS_PIN_GENERATOR_LOGGER_H
#define WPS_PIN_GENERATOR_LOGGER_H

#include <string>
#include <boost/shared_ptr.hpp>

/** Plain text logger
 */
class Logger {
private:
	/*** Debug log status switch
	 */
	static bool debugLogActive;

	/*** Verbouse log status switch
	 */
	static bool verbouseLogActive;

public:

	// Log commands

	/*** Log message
	 * @param messageLog
	 */
	virtual void log(const std::string &messageLog) const = 0;

	/*** Log only in verbouse mode
	 * @param messageLogVerbouse
	 */
	virtual void logVerbouse(const std::string &messageLogVerbouse) const = 0;

	/*** Log only in debug mode
	 * @param messageDebug
	 */
	virtual void logDebug(const std::string &messageDebug) const = 0;

	/*** Log error message
	 */
	virtual void logError(const std::string &messageError) const = 0;

	// Virtual destructor
	virtual ~Logger() {}

	// Debug mode getter and setter
	static bool isDebugLogActive();

	static void setDebugLogActive(bool debugLogActive);

	// Verbouse mode getter ad setter
	static bool isVerbouseLogActive();

	static void setVerbouseLogActive(bool verbouseLogActive);
};

#endif //WPS_PIN_GENERATOR_LOGGER_H
