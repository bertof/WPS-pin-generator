//
// Created by pily on 01/03/17.
//

#include "SplashScreen.h"
#include <iostream>
#include "../../lib/rang/include/rang.hpp"
#include "../Info/Info.h"

void SplashScreen::printSplashScreen() {
	std::cout << rang::style::reset << rang::style::bold << rang::fg::cyan
				 << Info::getProjectName() << rang::style::reset << std::endl;
}
