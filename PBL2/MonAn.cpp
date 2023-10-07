#include "MonAn.h"
#include "ChuanHoa.h"
#include <iomanip>


MonAn::MonAn()
{
    this->MaMon = this->TenMon = "";
    this->DonGia = 0;
    this->TinhTrang = false;
}
MonAn::MonAn(string ma, string ten, ll gia, bool tinhtrang)
{
    this->MaMon = ma;
    this->TenMon = ten;
    this->DonGia = gia;
    this->TinhTrang = tinhtrang;
}
MonAn::~MonAn()
{

}
void MonAn::swap(MonAn& a, MonAn& b)
{
    MonAn tmp("tmp", "tmp", 0, false);
    tmp = a;
    a = b;
    b = tmp;
}
string MonAn::getMaMon()
{
    return this->MaMon;
}
ll MonAn::getDonGia()
{
    return this->DonGia;
}
string MonAn::getTenMon()
{
    return this->TenMon;
}
bool MonAn::getTinhTrang()
{
    return this->TinhTrang;
}
void MonAn::setTenMon(string s)
{
    this->TenMon = s;
}
void MonAn::setDonGia(ll a)
{
    this->DonGia = a;
}
void MonAn::setTinhTrang(bool a)
{
    this->TinhTrang = a;
}
istream& operator >> (istream& in, MonAn & mon)
{
    cout << "\t\t\tNhap MA mon an: ";
    in >> mon.MaMon;
    in.ignore();
    cout << "\t\t\tNhap TEN mon an: ";  getline(in, mon.TenMon);
    mon.TenMon = ChuanHoa(mon.TenMon);
    cout << "\t\t\tNhap GIA TIEN mon an: "; in >> mon.DonGia;
    string x;
    do
    {
        cout << "\t\t\tNhap TINH TRANG mon an(1-con 0-het): ";
        in >> x;
    } while (x != "1" && x != "0" && cout << "\t\t\tNhap lai! \n");
    mon.TinhTrang = stoi(x);

    return in;
}
ostream& operator << (ostream& out, const MonAn& mon)
{
    out << "\t\t\t" << left << setw(8) << mon.MaMon << setw(20) << mon.TenMon << setw(9) << mon.DonGia << "    ";
    if(mon.TinhTrang)
        out << "Con" << endl;
    else
        out << "Het " << endl; 
    return out;
}
MonAn& MonAn::operator= (const MonAn& mon)
{
    this->MaMon = mon.MaMon;
    this->TenMon = mon.TenMon;
    this->DonGia = mon.DonGia;
    this->TinhTrang = mon.TinhTrang;
    return *this;
}