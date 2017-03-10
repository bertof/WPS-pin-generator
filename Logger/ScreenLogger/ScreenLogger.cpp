//
// Created by pily on 11/02/17.
//

#include "ScreenLogger.h"
#include "../../lib/rang/include/rang.hpp"
#include <ostream>
#include <string>

std::shared_ptr<ScreenLogger> ScreenLogger::mainScreenLoggerPtr = nullptr;

void ScreenLogger::log(const std::string &message) const {
  std::clog << rang::style::reset << message << std::endl;
}

void ScreenLogger::logError(const std::string &errorMessage) const {
  std::clog << rang::fg::red << "ERROR" << rang::style::reset << ":\t" << rang::fg::red
			<< errorMessage
			<< rang::style::reset << std::endl;

}

void ScreenLogger::logDebug(const std::string &string) const {
  if (Logger::isDebugLogActive()) {
	std::clog << rang::fg::cyan << "DBG" << rang::style::reset << ":\t" << string
			  << std::endl;
  }
}

void ScreenLogger::logVerbouse(const std::string &string) const {
  if (Logger::isVerbouseLogActive()) {
	std::clog << rang::fg::cyan << "VERB" << rang::style::reset << ":\t" << string
			  << std::endl;
  }
}

ScreenLogger::ScreenLogger() {}

std::shared_ptr<ScreenLogger> ScreenLogger::getScreenLogger() {
  if (mainScreenLoggerPtr == nullptr) {
	mainScreenLoggerPtr.reset(new ScreenLogger);
  }
  return mainScreenLoggerPtr;
}

