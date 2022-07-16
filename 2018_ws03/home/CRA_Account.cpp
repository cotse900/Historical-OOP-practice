//May 2022 Chungon Tse
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CRA_Account.h"
using namespace std;
namespace sict
{
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		if (sin < min_sin || sin > max_sin || familyName[0] == '\0' || givenName[0] == '\0') {
			strncpy(familyNem, "", sizeof(familyNem));//for invalid sin/names, leave the names blank
			strncpy(givenNem, "", sizeof(givenNem));
			sinNum = 0;
		}
		else {
			strncpy(familyNem, familyName, sizeof(familyNem));//copy valid names
			strncpy(givenNem, givenName, sizeof(givenNem));
			sinNum = sin;
		}
		numYears = 0;
		for (int i = 0; i < max_yrs; i++) {//the work is left for set year, balance
			years[i] = 0;
			bilancio[i] = 0;
		}
	};
	
	void CRA_Account::display() const {
		if (isEmpty()) {
			std::cout << "Account object is empty!" << std::endl;
		}
		else {
			std::cout << "Family Name: " << familyNem << std::endl;
			std::cout << "Given Name: " << givenNem << std::endl;
			std::cout << "CRA Account: " << sinNum << std::endl;

			for (int i = 0; i < numYears; i++) {
				std::cout.precision(2);
				if (bilancio[i] > 2) {
					std::cout << "Year (" << years[i] << ") balance owing: " << std::fixed << bilancio[i] << std::endl;
				}
				else if (bilancio[i] < -2) {
					std::cout << "Year (" << years[i] << ") refund due: " << std::fixed << bilancio[i]*-1 << std::endl;
				}
				else {
					std::cout << "Year (" << years[i] << ") No balance owing or refund due!" << std::endl;
				}
			}
		}
	};
	void CRA_Account::set(int year, double balance) {
		for (int i = 0; i < max_yrs; i++) {
			if (years[i] == 0) {
				years[i] = year;
				bilancio[i] = balance;
				numYears++;
				i = max_yrs;
			}
		}
	};
	bool CRA_Account::isEmpty() const {
		const int size = 9;
		int numero[size];
		int sinLocal = sinNum;
		int sum = 0, checkdigit = 0;
		if (sinLocal < min_sin || sinLocal > max_sin)
			return true;
		else {
			for (int i = 0; i < size; i++) {
				numero[size - 1 - i] = sinLocal % 10;
				sinLocal /= 10;//set sin digits into numero array
			}
			for (int i = 1; i < size; i += 2) {
				numero[i] += numero[i];//set alternates
				numero[i] = numero[i] / 10 + numero[i] % 10;
			}
			for (int i = 0; i < size - 1; i++)
				sum += numero[i];//add up sum of each digit
			if (sum % 10 == 0) checkdigit = 0;
			else checkdigit = (sum / 10 + 1) * 10 - sum;//sum divided by 10 is the lesser multiple of 10, so this (figure + 1)*10 is the next multiple of 10, and this multiple minus the sum. The difference is used below to see if it matches the checkdigit
			return checkdigit != numero[size - 1];
		}
	};
}