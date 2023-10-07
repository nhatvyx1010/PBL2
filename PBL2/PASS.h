#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
string PASS = "admin";
string getPass(string prompt)
{
    cout << prompt;
    string pass;
    char ch;
    while ((ch = _getch()) != 13)
    {
        if ((ch == 8))
        {
            if (pass.length() > 0)
            {
                cout << "\b \b";
                pass.resize(pass.length() - 1);
            }
        }
        else
        {
            pass += ch;
            cout << "*";
        }
    }
    return pass;
}