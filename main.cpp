#include <iostream>

#include "Graphics/SplashScreen/SplashScreen.h"

#include "Generator/bertofGenerator/Generator.h"
#include "Logger/ScreenLogger/ScreenLogger.h"
#include "Logger/DoubleLogger/DoubleLogger.h"

int main() {
	//TODO better spash screen
	//TODO input handling
	//TODO guide on how to use it (--help)
	std::cout << "WPS Pin Generator - by Bertof" << std::endl;

	//TODO test enabled debug
	DoubleLogger::setVerbouseLogActive(true);
	DoubleLogger::setDebugLogActive(true);
	DoubleLogger::setWriteOnLogFileActive(true);

	SplashScreen::printSplashScreen();

	GeneratorInterface *g = new bertof::Generator();

	g->generatePin("7C:5C:F8:F6:D0:B5");

	std::cout << "END MAIN" << std::endl;

	return 0;
}