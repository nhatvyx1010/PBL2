#include "ChiTietHoaDon.h"
#include <iomanip>

ChiTietHoaDon::ChiTietHoaDon()
{
}

ChiTietHoaDon::ChiTietHoaDon(string ma_mon, ll don_gia, int so_luong)
{
    this->Ma_Mon = ma_mon;
    this->Don_Gia = don_gia;
    this->So_Luong = so_luong;
}
ChiTietHoaDon::~ChiTietHoaDon()
{
}

//Ham Setter
void ChiTietHoaDon::setSo_Luong(int so_luong)
{
     this->So_Luong = so_luong;
}

// Ham Getter
string ChiTietHoaDon::getMa_Mon()
{
    return this->Ma_Mon;
}
ll ChiTietHoaDon::getDon_Gia()
{
    return this->Don_Gia;
}
int ChiTietHoaDon::getSo_Luong()
{
    return this->So_Luong;
}
void ChiTietHoaDon::Input(QLMonAn& Mon){
    int n;
    do 
    {  
    cout << "\n\t\t\tNhap ma hang hoa: "; cin >> this->Ma_Mon;
    n = Mon.FindIndexMa(this->Ma_Mon);
    if (n == -1) 
        cout << "\t\t\tMa hang hoa chua ton tai. Nhap lai!" << endl;
    } while(n == -1);
    this->Don_Gia = Mon.dataMonAn[n]->getDonGia();
    cout << "\t\t\tNhap So Luong Mon An: "; cin >> this->So_Luong;
}
void ChiTietHoaDon::Output(QLMonAn& Mon)
{
    int n = Mon.FindIndexMa(this->Ma_Mon);
    cout << left << setfill(' ') <<  "\t\t\t|   " << setw(21) << Mon.dataMonAn[n]->getTenMon() << " |      " << setw(8) << Mon.dataMonAn[n]->getDonGia() << " |        " << setw(7) << this->So_Luong << " | " << endl;
}