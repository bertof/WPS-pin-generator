//
// Created by pily on 11/02/17.
//

#include "TextLogger.h"
#include "../ScreenLogger/ScreenLogger.h"
#include <boost/filesystem/fstream.hpp>
#include <boost/date_time.hpp>

std::shared_ptr<TextLogger> TextLogger::mainTextLoggerPtr = nullptr;

const std::string TextLogger::DEFAULT_FILE_PATH = "log.txt";

bool TextLogger::writeOnFileActive = false;

/** Logs a message in the log file
 * Logs the message passed in the log file
 * @param message
 */
void TextLogger::log(const std::string &message) const {
  logText(message);
}

/** Logs an error message
 * Logs in the log file an error message
 * @param errorMessage
 */
void TextLogger::logError(const std::string &errorMessage) const {
  logText("ERROR:\t" + errorMessage);
}

/** Log a debug message
 * If debugging is enabled loggs the message passed in the log file
 * @param debugMessage
 */
void TextLogger::logDebug(const std::string &debugMessage) const {
  if (Logger::isDebugLogActive()) {
	logText("DBG:\t" + debugMessage);
  }
}

/** Constructor
 * Checks if the file path chosen is safely portable or not
 * @param filePath
 */
TextLogger::TextLogger(const std::string &filePath) : filePath(filePath) {
  if (!boost::filesystem::portable_name(filePath)) {
	std::shared_ptr<ScreenLogger> l = ScreenLogger::getScreenLogger();
	l->logError("File path not portable. It may create problems.");
  }
}

/** Opens file and appends the message passed
 * @param message	text to write in the log file
 */
void TextLogger::logText(const std::string &message) const {
  if (TextLogger::isWriteOnFileActive()) {
	boost::filesystem::fstream fileOutput;
	fileOutput.open(filePath, std::ofstream::app);
	if (!fileOutput.is_open()) {
	  std::shared_ptr<ScreenLogger> l = ScreenLogger::getScreenLogger();
	  l->logError("Can't open the log file (" + filePath + ")");
	} else {
	  std::string nowString = boost::posix_time::to_simple_string(boost::posix_time::second_clock::local_time());
	  fileOutput << nowString << "\t" << message << std::endl;
	  fileOutput.close();
	}
  }
}

void TextLogger::logVerbouse(const std::string &verbouseMessage) const {
  if (Logger::isVerbouseLogActive()) {
	logText("VERB:\t" + verbouseMessage);
  }
}

bool TextLogger::isWriteOnFileActive() {
  return writeOnFileActive;
}

void TextLogger::setWriteOnFileActive(bool status) {
  TextLogger::writeOnFileActive = status;
}

std::shared_ptr<TextLogger> TextLogger::getTextLogger(const std::string &filePath) {
  if (mainTextLoggerPtr == nullptr) {
	mainTextLoggerPtr.reset(new TextLogger(filePath));
  }
  return mainTextLoggerPtr;
}

const std::string &TextLogger::getFilePath() const {
  return filePath;
}


