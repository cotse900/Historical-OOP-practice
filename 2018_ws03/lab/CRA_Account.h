//May 2022 Chungon Tse
#ifndef _CRA_ACCOUNT_H
#define _CRA_ACCOUNT_H

namespace sict
{
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account
	{
		char familyNem[max_name_length + 1];
		char givenNem[max_name_length + 1];
		int sinNum;

	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
	};
}

#endif // !_CRA_ACCOUNT_H