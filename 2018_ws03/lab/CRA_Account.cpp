//May 2022 Chungon Tse
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CRA_Account.h"

namespace sict
{
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		if (sin >= min_sin && sin <= max_sin) {
			strncpy(familyNem, familyName, sizeof(familyNem));
			strncpy(givenNem, givenName, sizeof(givenNem));
			sinNum = sin;
		}
	};
	bool CRA_Account::isEmpty() const {
		return (sinNum < min_sin || sinNum > max_sin);
	};
	void CRA_Account::display() const {
		if (isEmpty()) {
			std::cout << "Account object is empty!" << std::endl;
		}
		else {
			std::cout << "Family Name: " << familyNem << std::endl;
			std::cout << "Given Name: " << givenNem << std::endl;
			std::cout << "CRA Account: " << sinNum << std::endl;
		}
	};
}