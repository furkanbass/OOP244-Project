/******************************************************************************
					 OOP244 Project Milestone-5
Full Name : Furkan BAS
Student ID#: 121540215
Email : fbas@myseneca.ca
Section : ZBB
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
******************************************************************************/
#ifndef SDDS_ERROR_H
#define SDDS_ERROR_H
#include <iostream>

namespace sdds {
	struct Error {

		char* m_errMsg;

	public:

		Error();
		Error(const char* errMsg);
		~Error();

		void clear();
		void setEmpty();

		operator bool() const;

		Error& operator=(const Error& src);
		Error(const Error& src);

		std::ostream& display(std::ostream& ostr = std::cout) const;

	};
	std::ostream& operator<<(std::ostream& ostr, const Error& num);
}
#endif
