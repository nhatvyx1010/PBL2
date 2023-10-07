#pragma once
#include "ChiTietHoaDon.h"

using ll = long long;

static int mhd = 1;
class HoaDon
{
    private:
        int Ma_HoaDon;
        int Length;
        Date Ngay_Ban;
        ll Thanh_Tien;
        List<ChiTietHoaDon*> cthd;  
    public:
        HoaDon();
        HoaDon(int, int, Date, ll);
        ~HoaDon();
        //getter
        int getMa_HoaDon();
        int getLength();
        Date getNgay_Ban();
        ll getThanh_Tien();
        //setter
        void setMa_HoaDon(int);
        void setLength(int);
        void setNgay_Ban(Date);
        void setThanh_Tien(ll);

        void Input(QLMonAn&, int);
        void Output (QLMonAn&);
        void Insert(QLMonAn&);
};