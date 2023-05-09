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
#ifndef SDDS_POSAPP_H_
#define SDDS_POSAPP_H_
#include "POS.h"
#include "Item.h"
#include "NonPerishable.h"
#include "Perishable.h"

#include <iostream>
namespace sdds {
	class PosApp {
		int nptr;
		char* m_filename;
		Item* Iptr[MAX_NO_ITEMS];

	public:
		void setEmpty();

		PosApp();
		PosApp(const char* File);
		~PosApp();

		void run();
		void menu();

		void listItems();
		void addItem();
		void removeItem();
		void stockItem();
		void POS();
		void saveRecs();
		void loadRecs();
		//std::ifstream& loadRecs(std::ifstream& ifstr);
	};

}

#endif