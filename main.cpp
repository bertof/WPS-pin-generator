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

	// Spash screen
	std::cout << SplashScreen::getSplashScreen() << std::endl;

	// Handle input
	InputHandler::handle(argc, argv);

	// Choose the generator
	GeneratorInterface *g = new bertof::Generator();

	// Generate pins
	std::vector<Pin> solution = g->generatePin("7C:5C:F8:F6:D0:B5");

	// TODO show the pins
	std::cout << "Solution:\t" << std::endl;
	for (int i = 0; i < solution.size(); ++i) {
		std::cout << i + 1 << ":\t" << solution[i].toString() << std::endl;
	}


	// END
	std::cout << "END MAIN" << std::endl;

	return 0;
}