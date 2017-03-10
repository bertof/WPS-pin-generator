//
// Created by pily on 28/02/17.
//

#include "DoubleLogger.h"

DoubleLogger::DoubleLogger(const std::string &filePath)
	: sLogger(ScreenLogger::getScreenLogger()), tLogger(TextLogger::getTextLogger(filePath)) {}
void DoubleLogger::log(const std::string &message) const {
  sLogger->log(message);
  tLogger->log(message);
}
void DoubleLogger::logError(const std::string &errorMessage) const {
  sLogger->logError(errorMessage);
  tLogger->logError(errorMessage);
}
void DoubleLogger::logDebug(const std::string &debugMessage) const {
  sLogger->logDebug(debugMessage);
  tLogger->logDebug(debugMessage);
}
void DoubleLogger::logVerbouse(const std::string &verbouseMessage) const {
  sLogger->logVerbouse(verbouseMessage);
  tLogger->logVerbouse(verbouseMessage);
}
