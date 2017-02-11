//
// Created by pily on 11/02/17.
//

#ifndef WPS_PIN_GENERATOR_NOTIMPLEMENTEDEXCEPTION_H
#define WPS_PIN_GENERATOR_NOTIMPLEMENTEDEXCEPTION_H

#include <exception>
#include <string>

class NotImplementedException : public std::exception {
public:
	/** Constructor (C strings).
     *  @param message C-style string error message.
     *                 The string contents are copied upon construction.
     *                 Hence, responsibility for deleting the char* lies
     *                 with the caller.
     */
	explicit NotImplementedException(const char *message) :
			errorMessage_(message) {
	}

	/** Constructor (C++ STL strings).
	 *  @param message The error message.
	 */
	explicit NotImplementedException(const std::string &message = "Function not implemented") :
			errorMessage_(message) {}

	/** Destructor.
	 * Virtual to allow for subclassing.
	 */
	virtual ~NotImplementedException() throw() {}

	/** Returns a pointer to the (constant) error description.
	 *  @return	A pointer to a const char*. The underlying memory
	 *          is in posession of the Exception object. Callers must
	 *          not attempt to free the memory.
	 */
	virtual const char *what() const throw() {
		return errorMessage_.c_str();
	}

protected:
	/** Error message.
	 */
	std::string errorMessage_;
};


#endif //WPS_PIN_GENERATOR_NOTIMPLEMENTEDEXCEPTION_H
