#include "rang.hpp"

int main()
{
	std::cout << std::endl
	          << rang::control::forceColor  // For appveyor terminal
	          << rang::style::reset << rang::bg::green << rang::fg::gray
	          << "If you're seeing green background, then rang works!"
	          << rang::style::reset << std::endl;
	return 0;
}
