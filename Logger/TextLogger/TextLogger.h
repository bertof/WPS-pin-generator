//
// Created by pily on 11/02/17.
//

#ifndef WPS_PIN_GENERATOR_TEXTLOGGER_H
#define WPS_PIN_GENERATOR_TEXTLOGGER_H

#include "../Logger.h"

class TextLogger : public Logger {
public:
	TextLogger(const std::string &filePath = "log.txt");

	virtual ~TextLogger() {}

	virtual void log(const std::string &message) const override;

	virtual void logError(const std::string &messageError) const override;

	virtual void logDebug(const std::string &messageDebug) const override;

	virtual void logVerbouse(const std::string &messageLogVerbouse) const override;

protected:
	virtual void logText(const std::string &message) const;

	const std::string filePath;
};


#endif //WPS_PIN_GENERATOR_TEXTLOGGER_H
