#pragma once
#include "Date.h"

using ll = long long;
// MON AN
class MonAn
{
    private:
        string MaMon;
        string TenMon;
        ll DonGia;
        bool TinhTrang;

    public:
        //constructor
        MonAn();
        MonAn(string, string, ll, bool);
        ~MonAn();
        void Show();
        // get set  
        string getMaMon();
        ll getDonGia();
        string getTenMon();
        bool getTinhTrang();
        void setTenMon(string);
        void setDonGia(ll);
        void setTinhTrang(bool);
        
        friend istream& operator >> (istream&, MonAn&);
        friend ostream& operator << (ostream&, const MonAn&);
        MonAn& operator = (const MonAn&);

        void swap(MonAn&, MonAn&);
        friend class QLMonAn;
        friend class HoaDon;

};