#include <iostream>
#include "Generator/Generator.h"
#include "Logger/ScreenLogger/ScreenLogger.h"

int main() {
	std::cout << "WPS Pin Generator - by Bertof" << std::endl;

	//TODO test enabled debug
	Logger::setDebugLogActive(true);

	Generator g = Generator();

	g.generatePin("7C:5C:F8:F6:D0:B5");

	std::cout << "END MAIN" << std::endl;

	return 0;
}