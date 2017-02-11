//
// Created by pily on 11/02/17.
//

#ifndef WPS_PIN_GENERATOR_DEBUGGER_H
#define WPS_PIN_GENERATOR_DEBUGGER_H

#include "../Logger.h"

#include <string>
#include <ostream>

class ScreenLogger : public Logger {

public:
	virtual ~ScreenLogger() {}

	virtual void log(const std::string &string);

	virtual void logError(const std::string &string);

	virtual void logDebug(const std::string &string);

};


#endif //WPS_PIN_GENERATOR_DEBUGGER_H
