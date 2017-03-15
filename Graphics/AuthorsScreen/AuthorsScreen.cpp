//
// Created by pily on 15/03/17.
//

#include "AuthorsScreen.h"
#include <string>
#include "../Info/Info.h"
#include "../../lib/rang/include/rang.hpp"

void AuthorsScreen::printAuthorsScreen() {

	std::cout << rang::style::reset << rang::fg::green << "AUTHORS" << rang::style::reset << std::endl
																													  << Info::getAuthorInfos()
																													  << std::endl;
}
