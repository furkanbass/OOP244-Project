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
#include "Item.h"
#include "PosIO.h"
#include "Date.h"

using namespace std;

namespace sdds {
	Item::Item() {
		setEmpty();
	}

	Item::~Item() {
		delete[] m_Name;
		m_Name = nullptr;
		m_ErrorState.clear();
	}

	Item::Item(const Item& src) {
		setEmpty();
		if (this != &src)
		{
			delete[] m_Name;
			if (src.m_Name != nullptr)
			{
				strcpy(m_SKU, src.m_SKU);
				m_Name = new char[strlen(src.m_Name) + 1];
				strcpy(m_Name, src.m_Name);
				m_price = src.m_price;
				m_Taxed = src.m_Taxed;
				m_Quantity = src.m_Quantity;
			}
			else
			{
				m_Name = nullptr;
			}
		}
	}

	Item& Item::operator=(const Item& src) {
		//setEmpty();
		if (this != &src)
		{
			delete[] m_Name;
			if (src.m_Name != nullptr)
			{
				strcpy(m_SKU, src.m_SKU);
				m_Name = new char[strlen(src.m_Name) + 1];
				strcpy(m_Name, src.m_Name);
				m_price = src.m_price;
				m_Taxed = src.m_Taxed;
				m_Quantity = src.m_Quantity;
			}
		}
		return *this;
	}

	bool Item::operator==(const char* sku) const {
		return strcmp(m_SKU, sku) == 0;
	}

	bool Item::operator>(const Item& item) const {
		return strcmp(this->m_Name, item.m_Name) > 0;
	}

	int Item::operator+=(int qnty) {
		return m_Quantity += qnty;
	}

	int Item::operator-=(int qnty) {
		return m_Quantity -= qnty;
	}

	Item::operator bool() const {
		return (m_Name != nullptr);
	}

	double operator+=(double& cost, const Item& item) {
		return cost += item.cost() * item.quantity();
	}

	Item& Item::displayType(int type) {
		m_displayType = type;
		return *this;
	}

	double Item::cost()const {
		double price = 0.0;

		if (m_Taxed)
		{
			price = (m_price * 1.13);
		}
		else
		{
			price = m_price;
		}

		return price;
	}

	int Item::quantity()const {
		return m_Quantity;
	}

	Item& Item::clear() {
		m_ErrorState.clear();
		return *this;
	}

	void Item::setEmpty() {
		m_SKU[0] = '\0';
		m_Name = nullptr;
		m_price = 0.0;
		m_Taxed = false;
		m_Quantity = 0;
		m_ErrorState.clear();
	}

	bool Item::isEmpty() const {
		return (m_SKU[0] == '\0' && m_Name == nullptr && m_price == 0.0 &&
			m_Taxed == false && m_Quantity == 0);
	}

	std::ostream& Item::write(std::ostream& ostr) const {
		char temp[1000];
		if (m_ErrorState)
		{
			ostr << m_ErrorState;
		}
		else
		{
			if (m_displayType == 1)
			{
				ostr.fill(' ');
				ostr.width(7);
				ostr.setf(ios::left);
				ostr << m_SKU << "|";

				ostr.width(20);
				if (strlen(m_Name) > 20)
				{
					//	m_Name[20] = '\0';
					strcpy(temp, m_Name);
					temp[20] = '\0';
					ostr << temp;
				}
				else
				{
					ostr.width(20);
					ostr << m_Name;
				}
				ostr << "|";

				ostr.setf(ios::right);
				ostr.width(7);
				cout.setf(ios::fixed);
				cout.precision(2);
				ostr << m_price;

				if (m_Taxed)
				{
					ostr << "| X |";
				}
				else
				{
					ostr << "|   |";
				}
				ostr.unsetf(ios::left);
				ostr.width(4);
				ostr.setf(ios::right);
				ostr << m_Quantity << "|";

				if (m_Taxed)
				{
					ostr.width(9);
					ostr << m_price * m_Quantity * 1.13 << "|";
				}
				else
				{
					ostr.width(9);
					ostr << (m_price * m_Quantity) << "|";
				}
				ostr.unsetf(ios::right);
				cout.unsetf(ios::fixed);
			}
			else
			{
				ostr << "=============v" << endl;
				ostr << "Name:        " << m_Name << endl;
				ostr << "Sku:         " << m_SKU << endl;
				ostr.setf(ios::fixed);
				ostr.precision(2);
				ostr << "Price:       " << m_price << endl;
				if (m_Taxed)
				{
					ostr << "Price + tax: " << (m_price * 1.13) << endl;
				}
				else
				{
					ostr << "Price + tax: N/A" << endl;
				}
				ostr << "Stock Qty:   " << m_Quantity << endl;
			}
		}
		return ostr;
	}

	std::istream& Item::read(std::istream& istr) {
		bool valid = false;
		char temp[10000], tax;

		cout << "Sku" << endl;
		while (!valid)
		{
			cout << "> ";
			istr.getline(temp, 10000);
			if (strlen(temp) > 5)
			{
				cout << "SKU too long" << endl;
				valid = false;
			}
			else
			{
				strcpy(m_SKU, temp);
				valid = true;
			}
			istr.clear();
		}

		valid = false;
		cout << "Name" << endl;
		while (!valid)
		{
			cout << "> ";
			istr.getline(temp, 1000);
			if (m_Name != nullptr)
			{
				delete[] m_Name;
				m_Name = nullptr;
			}
			if (strlen(temp) > 40)
			{
				istr.clear();
				cout << "Item name too long" << endl;
				valid = false;
			}
			else
			{
				m_Name = new char[strlen(temp) + 1];
				strcpy(m_Name, temp);
				valid = true;
			}
		}

		valid = false;
		cout << "Price" << endl;
		while (!valid)
		{
			cout << "> ";
			istr >> m_price;
			if (m_price < 0.0 || !istr)
			{
				istr.clear();
				istr.ignore(1000, '\n');
				cout << "Invalid price value" << endl;
				valid = false;
			}
			else
			{
				valid = true;
				istr.clear();
				istr.ignore(1000, '\n');
			}
		}

		valid = false;
		cout << "Taxed?" << endl;
		cout << "(Y)es/(N)o: ";
		while (!valid)
		{
			istr.get(tax);
			istr.ignore(1000, '\n');
			if (tax != 'y' && tax != 'n')
			{
				cout << "Only 'y' and 'n' are acceptable: ";
				istr.clear();
				valid = false;
			}
			else
			{
				if (tax == 'y')
				{
					m_Taxed = true;
					istr.clear();
				}
				else
				{
					m_Taxed = false;
					istr.clear();
				}
				valid = true;
			}
			istr.clear();
		}

		valid = false;
		cout << "Quantity" << endl;
		while (!valid)
		{
			cout << "> ";
			istr >> m_Quantity;
			if (m_Quantity < 1 || m_Quantity > 99 || !istr)
			{
				cout << "Invalid quantity value" << endl;
				istr.clear();
				istr.ignore(1000, '\n');
				valid = false;
			}
			else
			{
				valid = true;
			}
			istr.clear();
		}
		return istr;
	}

	std::ofstream& Item::save(std::ofstream& ofstr) const {
		if (m_ErrorState)
		{
			cerr << m_ErrorState;
		}
		else
		{
			ofstr.setf(ios::fixed);
			ofstr.precision(2);
			ofstr << itemType() << "," << m_SKU << "," << m_Name << "," << m_price << ",";
			if (m_Taxed)
			{
				ofstr << "1,";
			}
			else
			{
				ofstr << "0,";
			}
			ofstr << m_Quantity;
			if (itemType() == 'N')
			{
				ofstr << endl;
			}


		}
		return ofstr;
	}

	std::ifstream& Item::load(std::ifstream& ifstr) {
		m_ErrorState.clear();
		//setEmpty();
		string str = "";
		char name[1000];
		if (!ifstr.fail())
		{
			delete[] m_Name;
			getline(ifstr, str, ',');
			strcpy(m_SKU, str.c_str());

			if (strlen(m_SKU) > 5)
			{
				m_ErrorState = ERROR_POS_SKY;
				m_SKU[0] = '\0';
				m_Name = nullptr;
				m_price = 0.0;
				m_Taxed = false;
				m_Quantity = 0;
			}
			else
			{
				getline(ifstr, str, ',');
				strcpy(name, str.c_str());
				if (name[0] != '\0')
				{
					if (strlen(name) > 40)
					{
						m_ErrorState = ERROR_POS_NAME;
						m_SKU[0] = '\0';
						delete[] m_Name;
						m_Name = nullptr;
						m_price = 0.0;
						m_Taxed = false;
						m_Quantity = 0;
					}
					else
					{
						m_Name = new char[strlen(name) + 1];
						strcpy(m_Name, name);

						getline(ifstr, str, ',');
						m_price = stod(str);
						if (m_price < 0.0 || !ifstr)
						{
							m_ErrorState = ERROR_POS_PRICE;
							m_SKU[0] = '\0';
							delete[] m_Name;
							m_Name = nullptr;
							m_price = 0.0;
							m_Taxed = false;
							m_Quantity = 0;
						}
						else
						{
							getline(ifstr, str, ',');
							m_Taxed = stoi(str);
							if (m_Taxed != 1 && m_Taxed != 0)
							{
								m_ErrorState = ERROR_POS_TAX;
								m_SKU[0] = '\0';
								delete[] m_Name;
								m_Name = nullptr;
								m_price = 0.0;
								m_Taxed = false;
								m_Quantity = 0;
							}
							else
							{
								if (m_Taxed == 1)
								{
									m_Taxed = true;
								}
								else
								{
									m_Taxed = false;
								}

								if (itemType() == 'P')
								{
									getline(ifstr, str, ',');
									m_Quantity = stoi(str);

									if (m_Quantity < 1 || m_Quantity > 99 || !ifstr)
									{
										m_ErrorState = ERROR_POS_QTY;
										m_SKU[0] = '\0';
										delete[] m_Name;
										m_Name = nullptr;
										m_price = 0.0;
										m_Taxed = false;
										m_Quantity = 0;
									}
								}
								else
								{
									ifstr >> m_Quantity;
									if (m_Quantity < 1 || m_Quantity > 99 || !ifstr)
									{
										m_ErrorState = ERROR_POS_QTY;
										m_SKU[0] = '\0';
										delete[] m_Name;
										m_Name = nullptr;
										m_price = 0.0;
										m_Taxed = false;
										m_Quantity = 0;
									}
								}

							}
						}
					}
				}
			}
		}
		return ifstr;
	}

	std::ostream& Item::bprint(std::ostream& ostr) const {
		char temp[1000];
		ostr << "| ";
		ostr.fill(' ');
		ostr.width(20);
		ostr.setf(ios::left);
		if (strlen(m_Name) > 20)
		{
			strcpy(temp, m_Name);
			temp[20] = '\0';
			ostr << temp;
		}
		else
		{
			ostr << m_Name;
		}
		ostr << "|";

		ostr.setf(ios::right);
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr.width(10);
		if (m_Taxed)
		{
			ostr << (m_price * 1.13);
		}
		else
		{
			ostr << (m_price);
		}

		if (m_Taxed)
		{
			ostr << " |  T  |";
		}
		else
		{
			ostr << " |     |";
		}
		ostr << endl;
		ostr.unsetf(ios::right);
		return ostr;
	}
}