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
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include "Error.h"

namespace sdds {
	struct Date {
		int m_year;
		int m_month;
		int m_day;
		int m_hour;
		int m_minute;

		bool m_dateOnly;

		struct Error m_errors;


	public:

		Date();
		Date(int year, int mon, int day, int hour = 0, int min = 0);
		//~Date();

		bool operator==(const Date& right) const;
		bool operator!=(const Date& right) const;
		bool operator<(const Date& right) const;
		bool operator>(const Date& right) const;
		bool operator<=(const Date& right) const;
		bool operator>=(const Date& right) const;

		operator bool() const;

		const Error& error();
		Date& dateOnly(bool dateonly);
		void setEmpty();
		void validation(int year, int mon, int day, int hour, int min, bool dateonly);

		std::ostream& display(std::ostream& ostr = std::cout) const;
		std::istream& read(std::istream& istr = std::cin);

	};
	std::ostream& operator<<(std::ostream& ostr, const Date& info);
	std::istream& operator>>(std::istream& istr, Date& info);

}
#endif

