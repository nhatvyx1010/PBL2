#include "Date.h"
#include <iomanip>


Date::Date()
{
    this->Day = 20;
    this->Month = 10;
    this->Year = 2022;
}
Date::~Date()
{

}
int Date::getDay()
{
    return this->Day;
}
int Date::getMonth()
{
    return this->Month;
}
int Date::getYear()
{
    return this->Year;
}
void Date::Input()
{
    do
    {
        cout << "\t\t\tNam: "; cin >> Year;
    }while(Year < 1);
    
    do
    {
        cout << "\t\t\tThang: "; cin >> Month;
    } while (Month > 12 || Month < 1);

    switch (Month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        do
        {
            cout << "\t\t\tNgay: "; cin >> Day;
        } while (Day > 31 || Day < 1);
        break;
    case 2:
        do
        {
            cout << "\t\t\tNgay: "; cin >> Day;
        } while (Day > 29 || Day < 1);
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        do
        {
            cout << "\t\t\tNgay: "; cin >> Day;
        } while (Day > 30 || Day < 1);
        break;
    default:
        break;
    }
}
istream& operator >>(istream& in, Date& a)
{
    char x, y;
    in >> a.Day >> x >> a.Month >> y >> a.Year;
    return in;
}
ostream& operator << (ostream& out, Date a)
{
    out << right << setfill('0') << setw(2) << a.Day << "/" << setfill('0') << setw(2) << a.Month << "/" << setw(4) << a.Year << endl;
    return out;
}
bool operator<(const Date a, const Date b)
{
    if(a.Year==b.Year)
    {
        if(a.Month==b.Month)
        {
            return a.Day<b.Day;
        }
        else return a.Month<b.Month;
    }
    else return a.Year<b.Year;
}
bool operator==(const Date a, const Date b)
{
    if(a.Day==b.Day && a.Month==b.Month && a.Year==b.Year)
        return true;
    else return false;
}
bool operator!=(const Date a, const Date b)
{
    if(a.Day!=b.Day || a.Month!=b.Month || a.Year!=b.Year)
        return true;
    else return false;
}
void Date::Output()
{
    cout << right << setfill('0') << setw(2) << this->Day << "/" << setfill('0') << setw(2) << this->Month << "/" << setw(4) << this->Year << endl;;
}