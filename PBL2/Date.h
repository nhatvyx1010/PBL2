#pragma once
#include <iostream> 
using namespace std;

// DATE
class Date
{
    private:
        int Day, Month, Year;
    public:
        Date();
        ~Date();
        int getDay();
        int getMonth();
        int getYear();
        void Input();
        void Output();
        friend istream& operator >>(istream&, Date&);
        friend ostream& operator <<(ostream&, Date);
        friend bool operator<(const Date, const Date);
        friend bool operator==(const Date, const Date);
        friend bool operator!=(const Date, const Date);
};