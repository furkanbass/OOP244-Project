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
#ifndef SDDS_POSIO_H
#define SDDS_POSIO_H
#include <iostream>
#include <fstream>
using namespace std;

namespace sdds {
	class PosIO {

	public:
		virtual ~PosIO();
		virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;
		virtual std::istream& read(std::istream& istr = std::cin) = 0;
		virtual std::ofstream& save(std::ofstream& ofstr) const = 0;
		virtual std::ifstream& load(std::ifstream& ifstr) = 0;
	};
	std::ostream& operator<<(std::ostream& ostr, const PosIO& io);
	std::istream& operator>>(std::istream& istr, PosIO& io);
	std::ofstream& operator<<(std::ofstream& ofstr, const PosIO& io);
	std::ifstream& operator>>(std::ifstream& ifstr, PosIO& io);
}
#endif