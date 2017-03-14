#include <iostream>

#include "Graphics/SplashScreen/SplashScreen.h"
#include "InputHandling/InputHandler.h"

#include "Generator/bertofGenerator/Generator.h"

#include "Logger/ScreenLogger/ScreenLogger.h"
#include "Logger/DoubleLogger/DoubleLogger.h"
#include "lib/rang/include/rang.hpp"

int main(int argc, char *argv[]) {

	std::shared_ptr<DoubleLogger> logger(DoubleLogger::getDoubleLogger());
	//TODO better spash screen
	//TODO better input handling
	//TODO guide on how to use it (--help)
	//TODO switch to smart pointers

	// Spash screen
	logger->log(SplashScreen::getSplashScreen());

	// Handle input
	InputHandler::handle(argc, argv);

	// END
	logger->logDebug("END MAIN");

	return 0;
}