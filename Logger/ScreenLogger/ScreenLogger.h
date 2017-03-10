//
// Created by pily on 11/02/17.
//

#ifndef WPS_PIN_GENERATOR_DEBUGGER_H
#define WPS_PIN_GENERATOR_DEBUGGER_H

#include "../Logger.h"

#include <string>
#include <ostream>
#include <tkPort.h>

class ScreenLogger : virtual public Logger {

private:
	/*** Default constructor
	 */
	ScreenLogger();

	/*** Smart pointer to the main ScreenLogger object
	 * Points a real object only when the factory creates the first
	 */
	static std::shared_ptr<ScreenLogger> mainScreenLoggerPtr;

public:
	virtual ~ScreenLogger() {}

	/*** Log message
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
	 * @param messageLogVerbouse
	 */
	virtual void logVerbouse(const std::string &messageLogVerbouse) const override;

	/*** ScreenLogger singleton factory
	 * @return ScreenLogger singletor pointer
	 */
	static std::shared_ptr<ScreenLogger> getScreenLogger();
};


#endif //WPS_PIN_GENERATOR_DEBUGGER_H
