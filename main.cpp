#include <iostream>

#include "Graphics/SplashScreen/SplashScreen.h"
#include "InputHandling/InputHandler.h"

#include "Generator/bertofGenerator/Generator.h"

#include "Logger/ScreenLogger/ScreenLogger.h"
#include "Logger/DoubleLogger/DoubleLogger.h"
#include "lib/rang/include/rang.hpp"

int main(int argc, char *argv[]) {
  //TODO better spash screen
  //TODO better input handling
  //TODO guide on how to use it (--help)
  //TODO switch to smart pointers

  // Spash screen
  std::cout << SplashScreen::getSplashScreen() << std::endl;

  // Handle input
  InputHandler::handle(argc, argv);

  // END
  std::cout << "END MAIN" << std::endl;

  return 0;
}