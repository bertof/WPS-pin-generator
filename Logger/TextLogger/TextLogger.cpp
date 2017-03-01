//
// Created by pily on 11/02/17.
//

#include "TextLogger.h"
#include "../ScreenLogger/ScreenLogger.h"
#include <boost/filesystem/fstream.hpp>
#include <boost/date_time.hpp>

bool TextLogger::writeOnLogFileActive = false;

/** Logs a message in the log file
 * Logs the message passed in the log file
 * @param message
 */
void TextLogger::log(const std::string &message) const {
	logText(message);
}

/** Logs an error message
 * Logs in the log file an error message
 * @param messageError
 */
void TextLogger::logError(const std::string &messageError) const {
	logText("ERROR:\t" + messageError);
}

/** Log a debug message
 * If debugging is enabled loggs the message passed in the log file
 * @param messageDebug
 */
void TextLogger::logDebug(const std::string &messageDebug) const {
	if (Logger::isDebugLogActive()) {
		logText("DBG:\t" + messageDebug);
	}
}

/** Constructor
 * Checks if the file path chosen is safely portable or not
 * @param filePath
 */
TextLogger::TextLogger(const std::string &filePath) : filePath(filePath) {
	if (!boost::filesystem::portable_name(filePath)) {
		ScreenLogger l;
		l.logError("File path not portable. It may create problems.");
	}
}

/** Opens file and appends the message passed
 * @param message	text to write in the log file
 */
void TextLogger::logText(const std::string &message) const {
	if (TextLogger::isWriteOnLogFileActive()) {
		boost::filesystem::fstream fileOutput;
		fileOutput.open(filePath, std::ofstream::app);
		if (!fileOutput.is_open()) {
			ScreenLogger l;
			l.logError("Can't open the log file (" + filePath + ")");
		} else {
			std::string nowString = boost::posix_time::to_simple_string(boost::posix_time::second_clock::local_time());
			fileOutput << nowString << "\t" << message << std::endl;
			fileOutput.close();
		}
	}
}

void TextLogger::logVerbouse(const std::string &string) const {
	if (Logger::isVerbouseLogActive()) {
		logText("VERB:\t" + string);
	}
}

bool TextLogger::isWriteOnLogFileActive() {
	return writeOnLogFileActive;
}

void TextLogger::setWriteOnLogFileActive(bool writeOnLogFileActive) {
	TextLogger::writeOnLogFileActive = writeOnLogFileActive;
}


