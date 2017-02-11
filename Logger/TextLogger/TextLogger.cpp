//
// Created by pily on 11/02/17.
//

#include "TextLogger.h"
#include "../ScreenLogger/ScreenLogger.h"
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/path.hpp>

/** Logs a message in the log file
 * Logs the message passed in the log file
 * @param message
 */
void TextLogger::log(const std::string &message) {
	logText(message);
}

/** Logs an error message
 * Logs in the log file an error message
 * @param messageError
 */
void TextLogger::logError(const std::string &messageError) {
	logText("Error:\t" + messageError);
}

/** Log a debug message
 * If debugging is enabled loggs the message passed in the log file
 * @param messageDebug
 */
void TextLogger::logDebug(const std::string &messageDebug) {
	if (Logger::isDebugLogActive()) {
		logText("DEBUG:\t" + messageDebug);
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
void TextLogger::logText(const std::string &message) {
	boost::filesystem::fstream fileOutput;
	fileOutput.open(filePath, std::ofstream::app);
	if (!fileOutput.is_open()) {
		ScreenLogger l;
		l.logError("Can't open the log file (" + filePath + ")");
	} else {
		fileOutput << message << std::endl;
		fileOutput.close();
	}
}
