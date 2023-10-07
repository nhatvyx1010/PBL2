#include "ChuanHoa.h"
#include <string>
#include <sstream>
// Chuan Hoa Ten
string ChuanHoa(string name)
{
    stringstream ss(name);
    string res = "";
    string token;
    while(ss >> token)
    {
        res += toupper(token[0]);
        for(int i = 1; i < token.length(); i++)
        {
            res +=token[i];
        }
        res += " ";
    }
    res.erase(res.length()-1);
    return res;
}