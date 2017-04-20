#include "rang.hpp"

int main()
{

	// Visual test for background colors
	std::cout
	  << rang::control::forceColor << rang::bg::green
	  << "This text has green background." << rang::bg::reset << std::endl
	  << rang::bg::red << "This text has red background." << rang::bg::reset
	  << std::endl
	  << rang::bg::black << "This text has black background." << rang::bg::reset
	  << std::endl
	  << rang::bg::yellow << "This text has yellow background."
	  << rang::bg::reset << std::endl
	  << rang::bg::blue << "This text has blue background." << rang::bg::reset
	  << std::endl
	  << rang::bg::magenta << "This text has magenta background."
	  << rang::bg::reset << std::endl
	  << rang::bg::cyan << "This text has cyan background." << rang::bg::reset
	  << std::endl
	  << rang::bg::gray << rang::fg::black << "This text has gray background."
	  << rang::bg::reset << rang::style::reset << std::endl

	  << std::endl

	  // Visual test for foreground colors
	  << rang::fg::green << "This text has green color." << rang::fg::reset
	  << std::endl
	  << rang::fg::red << "This text has red color." << rang::fg::reset
	  << std::endl
	  << rang::fg::black << rang::bg::gray << "This text has black color."
	  << rang::fg::reset << rang::bg::reset << std::endl
	  << rang::fg::yellow << "This text has yellow color." << rang::fg::reset
	  << std::endl
	  << rang::fg::blue << "This text has blue color." << rang::fg::reset
	  << std::endl
	  << rang::fg::magenta << "This text has magenta color." << rang::fg::reset
	  << std::endl
	  << rang::fg::cyan << "This text has cyan color." << rang::fg::reset
	  << std::endl
	  << rang::fg::gray << "This text has gray color." << rang::style::reset
	  << std::endl

	  << std::endl

	  // Visual test for bright background colors
	  << rang::bgB::green << "This text has bright green background."
	  << std::endl
	  << rang::bgB::red << "This text has bright red background." << std::endl
	  << rang::bgB::black << "This text has bright black background."
	  << std::endl
	  << rang::bgB::yellow << rang::fg::black
	  << "This text has bright yellow background." << rang::style::reset
	  << std::endl
	  << rang::bgB::blue << "This text has bright blue background." << std::endl
	  << rang::bgB::magenta << "This text has bright magenta background."
	  << std::endl
	  << rang::bgB::cyan << "This text has bright cyan background." << std::endl
	  << rang::bgB::gray << rang::fg::black
	  << "This text has bright gray background." << rang::style::reset
	  << std::endl

	  << std::endl

	  // Visual test for bright foreground colors
	  << rang::fgB::green << "This text has bright green color." << std::endl
	  << rang::fgB::red << "This text has bright red color." << std::endl
	  << rang::fgB::black << "This text has bright black color." << std::endl
	  << rang::fgB::yellow << "This text has bright yellow color." << std::endl
	  << rang::fgB::blue << "This text has bright blue color." << std::endl
	  << rang::fgB::magenta << "This text has bright magenta color."
	  << std::endl
	  << rang::fgB::cyan << "This text has bright cyan color." << std::endl
	  << rang::fgB::gray << "This text has bright gray color."
	  << rang::style::reset << std::endl

	  << std::endl

	  // Visual test for text effects
	  << rang::style::bold << "This text is bold." << rang::style::reset
	  << std::endl
	  << rang::style::dim << "This text is dim." << rang::style::reset
	  << std::endl
	  << rang::style::italic << "This text is italic." << rang::style::reset
	  << std::endl
	  << rang::style::underline << "This text is underlined."
	  << rang::style::reset << std::endl
	  << rang::style::blink << "This text text has blink effect."
	  << rang::style::reset << std::endl
	  << rang::style::rblink << "This text text has rapid blink effect."
	  << rang::style::reset << std::endl
	  << rang::style::reversed << "This text is reversed." << rang::style::reset
	  << std::endl
	  << rang::style::conceal << "This text is concealed." << rang::style::reset
	  << std::endl
	  << rang::style::crossed << rang::fg::black << "This text is crossed."
	  << rang::style::reset << std::endl;

	return 0;
}
