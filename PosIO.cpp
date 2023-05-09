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
#include <fstream>
#include <cstring>
#include <string>
#include "PosIO.h"

using namespace std;
namespace sdds {
	PosIO::~PosIO() {
	}
	std::ostream& operator<<(std::ostream& ostr, const PosIO& io) {
		return io.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, PosIO& io) {
		return io.read(istr);
	}
	std::ofstream& operator<<(std::ofstream& ofstr, const PosIO& io) {
		return io.save(ofstr);
	}
	std::ifstream& operator>>(std::ifstream& ifstr, PosIO& io) {
		return io.load(ifstr);
	}
}