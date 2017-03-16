//
// Created by pily on 14/03/17.
//

#ifndef WPS_PIN_GENERATOR_HELPSCREENEXCEPTION_H
#define WPS_PIN_GENERATOR_HELPSCREENEXCEPTION_H

#include <exception>
#include <string>

class HelpScreenException : public std::exception {
public:
	/** Constructor (C string)
	* @param message	C-style string error message.
	* 						The string contents are copied upon construction.
	* 						Hence, responsibility for deleting the char* lies
	* 						with the caller.
	*/
	explicit HelpScreenException(const char *message) : errorMessage_(message) {}

	/** Constructor (C++ STL string)
	 * @param message	The error message.
	 */
	explicit HelpScreenException(const std::string &message = "Help screen showed") : errorMessage_(message) {}

	/** Destructor
	 * Virtual to allow subclassing
	 */
	virtual ~HelpScreenException() throw() {}

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

#endif //WPS_PIN_GENERATOR_HELPSCREENEXCEPTION_H
