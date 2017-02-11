//
// Created by pily on 11/02/17.
//

#ifndef WPS_PIN_GENERATOR_NOTIMPLEMENTEDEXCEPTION_H
#define WPS_PIN_GENERATOR_NOTIMPLEMENTEDEXCEPTION_H

#include <exception>
#include <string>

class NotImplementedException : public std::exception {

private:
	std::string errorMessage;

public:
	NotImplementedException(const char *error = "Functionality not implemented");
	const char * what();
};


#endif //WPS_PIN_GENERATOR_NOTIMPLEMENTEDEXCEPTION_H
