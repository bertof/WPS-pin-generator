#include "Generator.h"
#include "Pin.h"

#include <iostream>

int main() {
	std::cout << "WPS Pin Generator - by Bertof" << std::endl;

	GeneratorInterface *g = new Generator();

	Pin p = g->generatePin("TEST");

	std::cout<<"PIN:\t"<<p.toString()<<"\tVALID:\t"<<p.valid()<<std::endl;

	return 0;
}