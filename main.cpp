#include <iostream>
#include "Generator/bertofGenerator/Generator.h"
#include "Logger/ScreenLogger/ScreenLogger.h"

int main() {
	//TODO better spash screen
	//TODO input handling
	//TODO guide on how to use it (--help)
	std::cout << "WPS Pin Generator - by Bertof" << std::endl;

	//TODO test enabled debug
	Logger::setDebugLogActive(true);

	GeneratorInterface *g = new bertof::Generator();

	g->generatePin("7C:5C:F8:F6:D0:B5");

	std::cout << "END MAIN" << std::endl;

	return 0;
}