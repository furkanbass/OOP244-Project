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
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "NonPerishable.h"
using namespace std;

namespace sdds {

	char NonPerishable::itemType()const {
		return 'N';
	}

	std::ostream& NonPerishable::write(std::ostream& ostr) const {
		Item::write(ostr);
		if (*this)
		{
			if (m_displayType == 1)
			{
				ostr << "     N / A   |";
			}
			else
			{
				ostr << "=============^" << endl;
			}
		}
		return ostr;
	}
}