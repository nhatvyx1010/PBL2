#pragma once

#include "HoaDon.h"
#include "Date.h"
#include "QLMonAn.h"

class QLHoaDon{
    private:
        List <HoaDon*> dataHoaDon;
        List <Date*> dataDate;
        int lengthDate;
        int lengthHoaDon;
    public:
        QLHoaDon();
        ~QLHoaDon();

        int getLengthHoaDon();
        void setLengthHoaDon(int);

        void Insert(QLMonAn&);
        int FindIndexMaHD(const int);
        // int FindIndexMonAn(const string);
        void Remove();
        void Show(QLMonAn&);
        void Find(QLMonAn&);

        friend class ChiTietHoaDon;
        friend class Date;
};