//
// Created by pily on 11/02/17.
//

#ifndef WPS_PIN_GENERATOR_TEXTLOGGER_H
#define WPS_PIN_GENERATOR_TEXTLOGGER_H

#include "../Logger.h"

class TextLogger : virtual public Logger {
public:
	TextLogger();

	virtual ~TextLogger() {}

	virtual void log(const std::string &message) const override;

	virtual void logError(const std::string &messageError) const override;

	virtual void logDebug(const std::string &messageDebug) const override;

	virtual void logVerbouse(const std::string &messageLogVerbouse) const override;

protected:
	virtual void logText(const std::string &message) const;

private:
	/*** Controls if any TextLogger should write on a file
	 */
	static bool writeOnLogFileActive;

	/*** File path of the log file
	 */
	static std::string filePath;
public:
	static const std::string &getFilePath();

	static void setFilePath(const std::string &filePath);

public:
	/*** Getter for writeOnLogFileActive
	 * @return writeOnLogFileActive status
	 */
	static bool isWriteOnLogFileActive();

	/*** Setter for writeOnLogFileActive
	 * @param writeOnLogFileActive set to true to enable logging on a text file
	 */
	static void setWriteOnLogFileActive(bool writeOnLogFileActive);
};


#endif //WPS_PIN_GENERATOR_TEXTLOGGER_H
