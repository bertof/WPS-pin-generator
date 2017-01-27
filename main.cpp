#include "Pin/Pin.h"
#include "Generator/Generator.h"

#include <vector>
#include <iostream>

int main() {
	std::cout << "WPS Pin Generator - by Bertof" << std::endl;

	GeneratorInterface *g = new Generator();

	std::vector<Pin> p = g->generatePin("C8:3A:35:2D:9C:C0");

	std::cout << "PIN:\t" << p[0].toString() << "\tVALID:\t" << p[0].valid() << std::endl;

	return 0;
}