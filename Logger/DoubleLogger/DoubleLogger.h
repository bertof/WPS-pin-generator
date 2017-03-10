//
// Created by pily on 28/02/17.
//

#ifndef WPS_PIN_GENERATOR_DOUBLELOGGER_H
#define WPS_PIN_GENERATOR_DOUBLELOGGER_H

#include "../Logger.h"
#include "../ScreenLogger/ScreenLogger.h"
#include "../TextLogger/TextLogger.h"

class DoubleLogger : public Logger {
 protected:
  const std::shared_ptr<ScreenLogger> sLogger;
  const std::shared_ptr<TextLogger> tLogger;

 public:

  DoubleLogger(const std::string &filePath = TextLogger::DEFAULT_FILE_PATH);

  ~DoubleLogger() override {};

  void log(const std::string &message) const override;

  void logError(const std::string &errorMessage) const override;

  void logDebug(const std::string &debugMessage) const override;

  void logVerbouse(const std::string &verbouseMessage) const override;
};

#endif //WPS_PIN_GENERATOR_DOUBLELOGGER_H
