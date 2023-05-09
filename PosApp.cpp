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
#include <cctype>
#include "PosApp.h"
#include "POS.h"
#include "Item.h"
#include "Utils.h"
#include "Perishable.h"
#include "NonPerishable.h"

using namespace std;

namespace sdds {

	void PosApp::setEmpty() {
		m_filename = nullptr;
		for (int i = 0; i < MAX_NO_ITEMS; i++)
		{
			Iptr[i] = nullptr;
		}
		nptr = 0;
	}

	PosApp::PosApp() {
		setEmpty();
	}

	PosApp::PosApp(const char* File) {
		setEmpty();
		delete[] m_filename;
		m_filename = new char[strlen(File) + 1];
		strcpy(m_filename, File);
	}

	PosApp::~PosApp() {
		delete[] m_filename;
		m_filename = nullptr;

		//delete[] Iptr;
		for (int i = 0; i < MAX_NO_ITEMS; i++)
		{
			delete Iptr[i];
			Iptr[i] = nullptr;
		}
	}

	void PosApp::run() {
		cout.width(77);
		cout.setf(ios::left);
		cout.fill('.');
		cout << ">>>> Loading Items" << endl;

		//cout << "Loading data from " << m_filename << endl;
		menu();
	}

	void PosApp::menu() {
		int input;
		bool done = false, exit = false;

		while (!exit)
		{
			cout << "The Sene-Store" << endl;
			cout << "1- List items" << endl;
			cout << "2- Add item" << endl;
			cout << "3- Remove item" << endl;
			cout << "4- Stock item" << endl;
			cout << "5- POS" << endl;
			cout << "0- exit program" << endl;
			cout << "> ";

			done = false;
			while (!done)
			{
				cin >> input;

				if (!cin)
				{
					cout << "Invalid Integer, try again: ";
					cin.clear();
					cin.ignore(100000, '\n');
					done = false;
					exit = false;
				}
				else
				{
					if (input < 0 || input > 5)
					{
						cout << "[0<=value<=5], retry: > ";
						cin.clear();
						cin.ignore(100000, '\n');
						done = false;
						exit = false;
					}
					else
					{
						switch (input)
						{
						case 1:
							listItems();

							cin.clear();
							cin.ignore(100000, '\n');
							exit = false;
							//exit = false;
							break;

						case 2:
							addItem();

							cin.clear();
							cin.ignore(100000, '\n');
							exit = false;
							break;

						case 3:
							removeItem();

							cin.clear();
							cin.ignore(100000, '\n');
							exit = false;
							break;

						case 4:
							stockItem();

							cin.clear();
							cin.ignore(100000, '\n');
							exit = false;
							break;

						case 5:
							POS();

							cin.clear();
							cin.ignore(100000, '\n');
							exit = false;
							break;

						case 0:
							saveRecs();

							cin.clear();
							cin.ignore(100000, '\n');
							exit = true;
							break;
						}
						done = true;
					}
				}
			}
		}

	}
	void PosApp::listItems() {
		double total = 0.0;

		cout.width(77);
		cout.setf(ios::left);
		cout.fill('.');
		cout << ">>>> Listing Items" << endl;

		cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;
		cout << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;

		loadRecs();
		bubble(Iptr, nptr - 1);

		for (int i = 0; i < nptr - 1; i++) {
			cout.setf(ios::right);
			cout.fill(' ');
			cout.width(4);
			cout << i + 1 << " | ";
			cout.unsetf(ios::right);
			Iptr[i]->write(cout);
			total += Iptr[i]->cost() * Iptr[i]->quantity();
			cout << endl;
		}
		cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
		cout << "                               Total Asset: $  |";
		cout.setf(ios::right);
		cout.width(14);
		cout.precision(2);
		cout.setf(ios::fixed);
		cout << total << "|" << endl;
		cout << "-----------------------------------------------^--------------^" << endl << endl;
		cout.unsetf(ios::right);

	}
	void PosApp::addItem() {
		cout.width(77);
		cout.setf(ios::left);
		cout.fill('.');
		cout << ">>>> Adding Item to the store" << endl;

	}
	void PosApp::removeItem() {
		cout.width(77);
		cout.setf(ios::left);
		cout.fill('.');
		cout << ">>>> Remove Item" << endl;

	}
	void PosApp::stockItem() {
		cout.width(77);
		cout.setf(ios::left);
		cout.fill('.');
		cout << ">>>> Select an item to stock" << endl;

	}
	void PosApp::POS() {
		cout.width(77);
		cout.setf(ios::left);
		cout.fill('.');
		cout << ">>>> Starting Point of Sale" << endl;

	}
	void PosApp::saveRecs() {
		cout.width(77);
		cout.setf(ios::left);
		cout.fill('.');
		cout << ">>>> Saving Data" << endl;
		//cout << "Saving data in " << m_filename << endl;
		ofstream output(m_filename);
		output.setf(ios::fixed);
		output.precision(2);
		for (int i = 0; i < nptr - 1; i++)
		{
			Iptr[i]->save(output);
		}
		cout << "Goodbye!" << endl;
	}
	void PosApp::loadRecs() {
		ifstream input(m_filename);
		if (!input) {
			ofstream file(m_filename);
			file.close();
			input.open(m_filename);
		}
		//setEmpty();
		for (int i = 0; i < MAX_NO_ITEMS; i++)
		{
			Iptr[i] = nullptr;
		}
		nptr = 0;
		if (!input.fail())
		{
			for (int i = 0; input.good() && i < MAX_NO_ITEMS; i++) {
				char itemType;
				input >> itemType;
				input.ignore();
				if (itemType == 'N') {
					Iptr[i] = new NonPerishable();

				}
				else {
					Iptr[i] = new Perishable();
				}
				Iptr[i]->load(input);
				Iptr[i]->displayType(1);
				nptr++;
			}
			input.close();
		}
	}

}