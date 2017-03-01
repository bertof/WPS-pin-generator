//
// Created by pily on 01/03/17.
//

#include "SplashScreen.h"
#include <iostream>
#include "../../Logger/DoubleLogger/DoubleLogger.h"

void SplashScreen::printSplashScreen() {
	DoubleLogger logger;
	logger.logDebug("Splash screen");
	std::cout << SplashScreen::getSplashScreen() << std::endl;
}

std::string SplashScreen::getSplashScreen() {
	return "TEST";
}
