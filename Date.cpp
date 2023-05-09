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
#include <cstring>
#include <string>
#include <ctime>
#include "POS.h"
#include "Date.h"
#include "Utils.h"
using namespace std;

namespace sdds {

	Date::Date() {
		setEmpty();
		getSystemDate(m_year, m_month, m_day, m_hour, m_minute, m_dateOnly);
	}

	Date::Date(int year, int mon, int day, int hour, int min) {
		m_year = year;
		m_month = mon;
		m_day = day;
		m_hour = hour;
		m_minute = min;
		if (m_hour == 0 && m_minute == 0)
		{
			m_dateOnly = true;
		}
		else
		{
			m_dateOnly = false;
		}

		validation(year, mon, day, hour, min, m_dateOnly);

	}

	bool Date::operator==(const Date& right) const
	{
		return (this->m_year == right.m_year && this->m_month == right.m_month
			&& this->m_day == right.m_day && this->m_hour == right.m_hour);
	}
	bool Date::operator!=(const Date& right) const {
		return (this->m_year != right.m_year || this->m_month != right.m_month
			|| this->m_day != right.m_day || this->m_hour != right.m_hour);
	}
	bool Date::operator<(const Date& right) const {
		return (this->m_year < right.m_year || this->m_month < right.m_month
			|| this->m_day < right.m_day || this->m_hour < right.m_hour);
	}
	bool Date::operator>(const Date& right) const {
		return (this->m_year > right.m_year || this->m_month > right.m_month
			|| this->m_day > right.m_day || this->m_hour > right.m_hour);
	}
	bool Date::operator<=(const Date& right) const {
		return (this->m_year <= right.m_year || this->m_month <= right.m_month
			|| this->m_day <= right.m_day || this->m_hour <= right.m_hour);
	}
	bool Date::operator>=(const Date& right) const {
		return (this->m_year >= right.m_year || this->m_month >= right.m_month
			|| this->m_day >= right.m_day || this->m_hour >= right.m_hour);
	}

	Date& Date::dateOnly(bool dateonly) {
		m_dateOnly = dateonly;

		if (dateonly)
		{
			m_hour = 0;
			m_minute = 0;
		}

		return *this;
	}

	Date::operator bool() const {
		return (m_errors.m_errMsg == nullptr);
	}

	const Error& Date::error() {
		return m_errors;
	}

	void Date::setEmpty() {
		m_year = 0;
		m_month = 0;
		m_day = 0;
		m_hour = 0;
		m_minute = 0;

		m_dateOnly = false;
	}

	void Date::validation(int year, int mon, int day, int hour, int min, bool dateonly) {
		if (year >= MIN_YEAR && year <= MAX_YEAR)
		{
			m_year = year;

			if (mon > 0 && mon < 13)
			{
				m_month = mon;

				if (day > 0 && day <= daysOfMonth(year, mon))
				{
					m_day = day;

					if (dateonly)
					{
						m_hour = 0;
						m_minute = 0;
					}
					else
					{
						if (hour >= 0 && hour <= 23)
						{
							m_hour = hour;

							if (min >= 0 && min <= 59)
							{
								m_minute = min;
							}
							else
							{
								m_errors = "Invlid Minute";
							}
						}
						else
						{
							m_errors = "Invalid Hour";
						}
					}
				}
				else
				{
					m_errors = "Invalid Day";
				}
			}
			else
			{
				m_errors = "Invalid Month";
			}
		}
		else
		{
			m_errors = "Invalid Year";
		}
	}

	std::ostream& Date::display(std::ostream& ostr) const {
		if (m_errors.m_errMsg == nullptr)
		{
			if (m_dateOnly)
			{
				ostr << m_year << "/";

				if (m_month > -1 && m_month < 10)
				{
					ostr << "0" << m_month << "/";
				}
				else
				{
					ostr << m_month << "/";
				}
				if (m_day > -1 && m_day < 10)
				{
					ostr << "0" << m_day;
				}
				else
				{
					ostr << m_day;
				}
			}
			else
			{
				ostr << m_year << "/";
				if (m_month > -1 && m_month < 10)
				{
					ostr << "0" << m_month << "/";
				}
				else
				{
					ostr << m_month << "/";
				}
				if (m_day > -1 && m_day < 10)
				{
					ostr << "0" << m_day << ", ";
				}
				else
				{
					ostr << m_day << ", ";
				}
				if (m_hour > -1 && m_hour < 10)
				{
					ostr << "0" << m_hour << ":";
				}
				else
				{
					ostr << m_hour << ":";
				}
				if (m_minute > -1 && m_minute < 10)
				{
					ostr << "0" << m_minute;
				}
				else
				{
					ostr << m_minute;
				}

			}
		}
		else
		{
			if (m_dateOnly)
			{
				ostr << m_errors.m_errMsg << "(" << m_year << "/";
				if (m_month > -1 && m_month < 10)
				{
					ostr << "0" << m_month << "/";
				}
				else
				{
					ostr << m_month << "/";
				}
				if (m_day > -1 && m_day < 10)
				{
					ostr << "0" << m_day << ")";
				}
				else
				{
					ostr << m_day << ")";
				}


			}
			else
			{
				ostr << m_errors.m_errMsg << "(" << m_year << "/";
				if (m_month > -1 && m_month < 10)
				{
					ostr << "0" << m_month << "/";
				}
				else
				{
					ostr << m_month << "/";
				}
				if (m_day > -1 && m_day < 10)
				{
					ostr << "0" << m_day << ", ";
				}
				else
				{
					ostr << m_day << ", ";
				}
				if (m_hour > -1 && m_hour < 10)
				{
					ostr << "0" << m_hour << ":";
				}
				else
				{
					ostr << m_hour << ":";
				}
				if (m_minute > -1 && m_minute < 10)
				{
					ostr << "0" << m_minute << ")";
				}
				else
				{
					ostr << m_minute << ")";
				}
			}
		}
		return ostr;
	}
	std::istream& Date::read(std::istream& istr) {
		if (!m_errors)
		{
			m_errors.clear();

			if (m_dateOnly)
			{
				istr >> m_year;
				istr.ignore();
				if (istr.fail())
				{
					m_errors = "Cannot read year entry";
					m_year = 0;
					m_month = 0;
					m_day = 0;
					m_hour = 0;
					m_minute = 0;
				}
				else
				{
					istr >> m_month;
					istr.ignore();
					if (istr.fail())
					{
						m_errors = "Cannot read month entry";
						m_month = 0;
						m_day = 0;
						m_hour = 0;
						m_minute = 0;
					}
					else
					{
						istr >> m_day;
						if (istr.fail())
						{
							m_errors = "Cannot read day entry";
							m_day = 0;
							m_hour = 0;
							m_minute = 0;
						}
					}
				}
			}
			else
			{
				istr >> m_year;
				istr.ignore();
				if (istr.fail())
				{
					m_errors = "Cannot read year entry";
					m_year = 0;
					m_month = 0;
					m_day = 0;
					m_hour = 0;
					m_minute = 0;
				}
				else
				{
					istr >> m_month;
					istr.ignore();
					if (istr.fail())
					{
						m_errors = "Cannot read month entry";
						m_month = 0;
						m_day = 0;
						m_hour = 0;
						m_minute = 0;
					}
					else
					{
						istr >> m_day;
						istr.ignore();
						if (istr.fail())
						{
							m_errors = "Cannot read day entry";
							m_day = 0;
							m_hour = 0;
							m_minute = 0;
						}
						else
						{
							istr >> m_hour;
							istr.ignore();
							if (istr.fail())
							{
								m_errors = "Cannot read hour entry";
								m_hour = 0;
								m_minute = 0;
							}
							else
							{
								istr >> m_minute;
								if (istr.fail())
								{
									m_errors = "Cannot read minute entry";
									m_minute = 0;
								}
							}
						}
					}
				}
			}

			if (m_errors.m_errMsg == nullptr)
			{
				validation(m_year, m_month, m_day, m_hour, m_minute, m_dateOnly);
			}
		}

		return istr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Date& info) {
		return info.display(ostr);
	}

	std::istream& operator>>(std::istream& istr, Date& info) {
		return info.read(istr);
	}

}