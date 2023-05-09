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
#ifndef SDDS_NONPERISHABLE_H
#define SDDS_NONPERISHABLE_H
#include <iostream>
#include "Item.h"

namespace sdds {
	class NonPerishable : public Item {

	public:
		char itemType()const;

		std::ostream& write(std::ostream& ostr) const;

	};
}
#endif