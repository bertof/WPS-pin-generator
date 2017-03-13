//
// Created by pily on 11/02/17.
//

#ifndef WPS_PIN_GENERATOR_INVALIDINPUTEXCEPTION_H
#define WPS_PIN_GENERATOR_INVALIDINPUTEXCEPTION_H

#include <exception>
#include <string>

class InvalidInputException : public std::exception {
public:

	/** Constructor (C string)
	* @param message	C-style string error message.
	* 						The string contents are copied upon construction.
	* 						Hence, responsibility for deleting the char* lies
	* 						with the caller.
	*/
	explicit InvalidInputException(const char *message) : errorMessage_(message) {}

	/** Constructor (C++ STL string)
	 * @param message	The error message.
	 */
	explicit InvalidInputException(const std::string &message = "Input passed is not valid") : errorMessage_(message) {}

	/** Destructor
	 * Virtual to allow subclassing
	 */
	virtual ~InvalidInputException() throw() {}

	/** Returns a pointer to the (constant) error description.
	 *
	 * @return
	 */
	const char *what() const throw() {
		return errorMessage_.c_str();
	}

private:
	/** Saved error message
	 */
	std::string errorMessage_;
};

#endif //WPS_PIN_GENERATOR_INVALIDINPUTEXCEPTION_H
