#include <iostream>
#include "Generator/Generator.h"
#include "Debugger/Debugger.h"

int main() {
	std::cout << "WPS Pin Generator - by Bertof" << std::endl;

	Debugger::toggleDebugActivityStatus();

	Generator g = Generator();

	g.generatePin("7C:5C:F8:F6:D0:B5");

	std::cout << "END MAIN" << std::endl;

	return 0;
}