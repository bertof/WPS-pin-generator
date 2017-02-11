//
// Created by pily on 11/02/17.
//

#include "NotImplementedException.h"

NotImplementedException::NotImplementedException(const char *error) : errorMessage(error) {
}

const char *NotImplementedException::what() {
	return errorMessage.c_str();
}
