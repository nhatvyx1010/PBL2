#pragma once
#include "List.h"
#include "MonAn.h"

// QUAN LY MON AN
class QLMonAn
{
    private:
        List<MonAn*> dataMonAn;
        int LengthM_A;
    public:
        QLMonAn();
        ~QLMonAn();
        // set-get
        int getLengthM_A();
        void setLengthM_A(int);

        void Readf();
        void Show();
        void Insert();
        void Update();
        void Remove();
        void Writef();
        void Find();
        void Sort();
        void selectionsortGiaBan(bool (*cmp)(ll, ll));
        void selectionsortMa();
        int FindIndexMa(const string&);
        int FindIndexTen(const string&);
        void clear();   
        friend class ChiTietHoaDon;
        friend class MonAn;
};