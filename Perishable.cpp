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
#include <string>
#include <cstring>
#include <cctype>
#include "Perishable.h"
#include "Date.h"
#include "Item.h"

using namespace std;

namespace sdds {
	char Perishable::itemType()const {
		return 'P';
	}

	std::ostream& Perishable::write(std::ostream& ostr) const {
		Item::write(ostr);
		if (!ostr.fail())
		{
			if (m_displayType == 1)
			{
				ostr << "  ";
				ostr << m_expire.m_year << "/";

				if (m_expire.m_month > -1 && m_expire.m_month < 10)
				{
					ostr << "0" << m_expire.m_month << "/";
				}
				else
				{
					ostr << m_expire.m_month << "/";
				}
				if (m_expire.m_day > -1 && m_expire.m_day < 10)
				{
					ostr << "0" << m_expire.m_day << " |";
				}
				else
				{
					ostr << m_expire.m_day << " |";
				}
			}
			else
			{
				ostr << "Expiry date: " << m_expire.m_year << "/";

				if (m_expire.m_month > -1 && m_expire.m_month < 10)
				{
					ostr << "0" << m_expire.m_month << "/";
				}
				else
				{
					ostr << m_expire.m_month << "/";
				}
				if (m_expire.m_day > -1 && m_expire.m_day < 10)
				{
					ostr << "0" << m_expire.m_day;
				}
				else
				{
					ostr << m_expire.m_day;
				}
				ostr << endl;
				ostr << "=============^" << endl;
			}
		}
		return ostr;
	}
	std::istream& Perishable::read(std::istream& istr) {
		Date expire;
		if (!istr.fail())
		{
			Item::read(istr);
			expire.m_dateOnly = true;
			cout << "Expiry date (YYYY/MM/DD)" << endl;
			cout << "> ";
			expire.read(istr);
			m_expire.m_dateOnly = expire.m_dateOnly;
			m_expire.m_year = expire.m_year;
			m_expire.m_month = expire.m_month;
			m_expire.m_day = expire.m_day;
			m_expire.m_hour = expire.m_hour;
			m_expire.m_minute = expire.m_minute;

		}
		return istr;
	}
	std::ofstream& Perishable::save(std::ofstream& ofstr) const {
		Item::save(ofstr);
		if (!ofstr.fail())
		{
			ofstr << ",";
			ofstr << m_expire.m_year << "/";

			if (m_expire.m_month > -1 && m_expire.m_month < 10)
			{
				ofstr << "0" << m_expire.m_month << "/";
			}
			else
			{
				ofstr << m_expire.m_month << "/";
			}
			if (m_expire.m_day > -1 && m_expire.m_day < 10)
			{
				ofstr << "0" << m_expire.m_day << endl;
			}
			else
			{
				ofstr << m_expire.m_day << endl;
			}
		}
		return ofstr;
	}
	std::ifstream& Perishable::load(std::ifstream& ifstr) {

		if (!ifstr.fail())
		{
			Item::load(ifstr);
			m_expire.m_dateOnly = true;
			m_expire.read(ifstr);
		}
		return ifstr;
	}
}