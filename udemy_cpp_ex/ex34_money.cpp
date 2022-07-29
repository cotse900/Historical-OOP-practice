//Money.h
//-------
#ifndef _MONEY_MONEY_H
#define _MONEY_MONEY_H


#include <iostream>

class Money {
    int dollars;
    int cents;
public:
    Money(int dollars, int cents);
    Money(int total);


    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR METHOD DECLARATIONS BELOW THIS LINE----
    
    bool operator==(const Money &rhs) const;

    bool operator!=(const Money &rhs) const;
    
    //----WRITE YOUR METHOD DECLARATIONS ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
};

#endif //_MONEY_MONEY_H


//Money.cpp
//---------
#include "Money.h"

Money::Money(int dollars, int cents) : dollars(dollars), cents(cents) {}

Money::Money(int total) {
    dollars = total/100;
    cents = total % 100;
}

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR METHOD DEFINITIONS BELOW THIS LINE----

bool Money::operator==(const Money &money) const {
    return dollars == money.dollars &&
           cents == money.cents;
}

bool Money::operator!=(const Money &money) const {
    return !(money == *this);
}

//----WRITE YOUR METHOD DEFINITIONS ABOVE THIS LINE----
