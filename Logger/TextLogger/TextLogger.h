//
// Created by pily on 11/02/17.
//

#ifndef WPS_PIN_GENERATOR_TEXTLOGGER_H
#define WPS_PIN_GENERATOR_TEXTLOGGER_H

#include "../Logger.h"

class TextLogger : virtual public Logger {

 private:

  /*** Generic method to log on file
   * @param message
   */
  virtual void logText(const std::string &message) const;

 protected:

  /*** Main shared pointer to a TextLogger singleton
   */
  static std::shared_ptr<TextLogger> mainTextLoggerPtr;

  /*** Controls if any TextLogger should write on a file
   */
  static bool writeOnFileActive;

  /*** File path of the log file
   */
  const std::string filePath;

  /*** Default constructor
   */
  TextLogger(const std::string &logFilePath = DEFAULT_FILE_PATH);

 public:

  /*** Default for filePath
   */
  static const std::string DEFAULT_FILE_PATH;

  /*** Virtual default destructor
   */
  virtual ~TextLogger() {}

  /*** FilePath getter
   * @return
   */
  const std::string &getFilePath() const;

  /*** Log standard message
   * @param message
   */
  virtual void log(const std::string &message) const override;

  /*** Log error message
   * @param errorMessage
   */
  virtual void logError(const std::string &errorMessage) const override;

  /*** Log debug only message
   * @param debugMessage
   */
  virtual void logDebug(const std::string &debugMessage) const override;

  /*** Log verbouse only message
   * @param verbouseMessage
   */
  virtual void logVerbouse(const std::string &verbouseMessage) const override;

  /*** Getter for writeOnLogFileActive
   * @return writeOnFileActive status
   */
  static bool isWriteOnFileActive();

  /*** Setter for writeOnLogFileActive
   * @param status set to true to enable logging on a text file
   */
  static void setWriteOnFileActive(bool status);

  /*** TextLogger singleton pointer factory
   * @param filePath
   * @return
   */
  static std::shared_ptr<TextLogger> getTextLogger(const std::string &filePath);
};

#endif //WPS_PIN_GENERATOR_TEXTLOGGER_H
