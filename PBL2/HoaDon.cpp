#include "HoaDon.h"
#include <iomanip>
HoaDon::HoaDon()
{
    this->Ma_HoaDon = mhd++;
    this->Length = 0;
    this->Thanh_Tien = 0;   
}
HoaDon::HoaDon(int ma, int len, Date day, ll tong)
{
    Ma_HoaDon = ma;
    Length = len;
    Ngay_Ban = day;
    Thanh_Tien = tong;
}
HoaDon::~HoaDon()
{
}
// ham getset
int HoaDon::getMa_HoaDon()
{
    return this->Ma_HoaDon;
}
int HoaDon::getLength()
{
    return this->Length;
}
Date HoaDon::getNgay_Ban()
{
    return this->Ngay_Ban;
}
ll HoaDon::getThanh_Tien()
{
    return this->Thanh_Tien;
}
void HoaDon::setMa_HoaDon(int ma)
{
    this->Ma_HoaDon = ma;
}
void HoaDon::setNgay_Ban(Date day)
{
    this->Ngay_Ban = day;
}
void HoaDon::setLength(int len)
{
    this->Length = len;
}
void HoaDon::setThanh_Tien(ll tong)
{
    this->Thanh_Tien = tong;
}
void HoaDon::Input(QLMonAn& Mon, int MaHD)
{
    this->Ma_HoaDon = MaHD;
    int n;
    cout << "\t\t\t Ngay Ban: \n"; this->Ngay_Ban.Input();
    Mon.Show();
    Thanh_Tien = 0;
    char x; int i=0;
    do
    {
        cout << "\n\t\t\tThong tin chi tiet mon an: " << i+1 << endl;
        ChiTietHoaDon *p = new ChiTietHoaDon;
        p->Input(Mon);
        this->cthd.push_back(p);
        Length++;
        Thanh_Tien += this->cthd[i]->getDon_Gia()*(cthd[i]->getSo_Luong());
        i++;
        cout << "\t\t\tTiep tuc? (c/k): ";
        do
        {
            cin >> x;
        } while (x != 'c' && x != 'k');
    } while (x == 'c');
}
void HoaDon::Output(QLMonAn& Mon)
{
    cout << "\n\t\t\t1. Ma hoa don: " << this->Ma_HoaDon;
    cout << "\n\t\t\t2. Ngay lap: " << this->Ngay_Ban << endl;
    cout << "\t\t\t------------------------------------------------------------" << endl;
    cout << "\t\t\t" << "|      Ten hang hoa       |" << setw(9) << "    Don gia    |" << setw(15) << "    So luong    |" << endl;
    cout << "\t\t\t|----------------------------------------------------------|" << endl;
    cout << "\t\t\t|                          " << setw(9) << "                " << setw(15) << "                |" << endl;
    for (int i = 0; i < this->getLength(); i++)
    {
        this->cthd[i]->Output(Mon);
        if(i != this->getLength()-1)
        {
            cout << "\t\t\t" << "|                         |" << setw(9) << "               |" << setw(15) << "                |" << endl;
        }
        if(i == this->getLength()-1 )
        {
            for(int j=0; j<3; j++)
            {
                cout << "\t\t\t" << "|                          " << setw(9) << "                " << setw(15) << "                |" << endl;
            }
            cout << "\t\t\t|     ************************************************     |" << endl;
        }
    }
    for(int j=0; j<2; j++)
    {
        cout << "\t\t\t" << "|                          " << setw(9) << "                " << setw(15) << "                |" << endl;
    }
    cout << right << setfill(' ') << "\t\t\t|\t\t\t  THANH TIEN: " << setw(10) << this->Thanh_Tien << " $$        |" << endl;
    cout << "\t\t\t------------------------------------------------------------" << endl;
}
void HoaDon::Insert(QLMonAn& Mon)
{
    ChiTietHoaDon *p = new ChiTietHoaDon;
    p->Input(Mon);
    this->cthd.push_back(p);
    int n = this->getLength() + 1;
    this->setLength(n);
    cout << "\t\t\t Them Hoa Don Thanh Cong\n" << endl;
}