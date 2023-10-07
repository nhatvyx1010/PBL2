#pragma once
#include "QLMonAn.h"
using ll = long long;

class ChiTietHoaDon
{
    private:
        string Ma_Mon;
        ll Don_Gia;
        int So_Luong;
    public:
        ChiTietHoaDon();
        ChiTietHoaDon(string, ll, int);
        ~ChiTietHoaDon();

        void setSo_Luong(int);

        string getMa_Mon();
        ll getDon_Gia();
        int getSo_Luong();

        void Input(QLMonAn&);
        void Output(QLMonAn&);
        friend class HoaDon;
        friend class QLMonAn;
};