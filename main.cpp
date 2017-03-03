#include <iostream>

#include "Graphics/SplashScreen/SplashScreen.h"
#include "InputHandling/InputHandler.h"

#include "Generator/bertofGenerator/Generator.h"
#include "Logger/ScreenLogger/ScreenLogger.h"
#include "Logger/DoubleLogger/DoubleLogger.h"

int main(int argc, char *argv[]) {
	//TODO better spash screen
	//TODO better input handling
	//TODO guide on how to use it (--help)

	InputHandler::handle(argc, argv);

	SplashScreen::printSplashScreen();

	GeneratorInterface *g = new bertof::Generator();

	g->generatePin("7C:5C:F8:F6:D0:B5");

	std::cout << "END MAIN" << std::endl;

	return 0;
}