//
// Created by pily on 11/02/17.
//

#ifndef WPS_PIN_GENERATOR_DEBUGGER_H
#define WPS_PIN_GENERATOR_DEBUGGER_H

#include <string>
#include <ostream>

class Debugger {

public:
	static void log(const std::string &string);

	static void logError(const std::string &string);

	static void logDebug(const std::string &string);

	static bool toggleDebugActivityStatus(const bool &status = true);

	static bool isDebugActive();

private:
	static bool debugActivityStatus;
};


#endif //WPS_PIN_GENERATOR_DEBUGGER_H
