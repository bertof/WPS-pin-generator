//
// Created by pily on 28/02/17.
//

#ifndef WPS_PIN_GENERATOR_DOUBLELOGGER_H
#define WPS_PIN_GENERATOR_DOUBLELOGGER_H

#include "../Logger.h"
#include "../ScreenLogger/ScreenLogger.h"
#include "../TextLogger/TextLogger.h"

class DoubleLogger : public ScreenLogger, public TextLogger {
public:

	DoubleLogger(const std::string &filePath = "log.txt");

	~DoubleLogger() override {};

	void log(const std::string &string) const override;

	void logError(const std::string &string) const override;

	void logDebug(const std::string &string) const override;

	void logVerbouse(const std::string &messageLogVerbouse) const override;

};


#endif //WPS_PIN_GENERATOR_DOUBLELOGGER_H
