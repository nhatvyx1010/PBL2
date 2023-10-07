#include "QLMonAn.h"
#include "ChuanHoa.h"
#include <fstream>

QLMonAn::QLMonAn()
{
    this->LengthM_A = 0;
}
QLMonAn::~QLMonAn()
{

}
int QLMonAn::getLengthM_A()
{
    return this->LengthM_A;
}
void QLMonAn::setLengthM_A(int len)
{
    this->LengthM_A = len;
}
void QLMonAn::Insert()
{
    MonAn *Mon = new MonAn;
    cin >> *Mon;
    // Kiem tra MA mon co trung khong
    if(this->FindIndexMa(Mon->MaMon) != -1)
    {
        cout << "\t\t\t Ma Mon An '" << Mon->MaMon << "' Da ton tai!" << endl;
        return;
    }
    else
    {
        if(this->FindIndexTen(Mon->TenMon) != -1)
        {
            cout << "\t\t\t Ten Mon An '" << Mon->TenMon << "' Da ton tai!" << endl;
            return;
        }
        else
        {
            string ten = Mon->getTenMon();
            Mon->setTenMon(ChuanHoa(ten));
            
            dataMonAn.push_back(Mon);
            int n = this->getLengthM_A() + 1;
            this->setLengthM_A(n);

            cout << "\t\t\t Them Mon An Thanh Cong" << endl;
        }
    }
}
void QLMonAn::Readf()
{
    ifstream filein;
    filein.open("DsMonAn.txt");

    if(!filein)
    {
        cout << "\t\t\tKhong mo duoc file input!" << endl;
        return;
    }
    string Ma_Mon, Ten_Mon, TT;
    ll Gia;
    bool Tinh_Trang;
    char x = ',';
    while(filein.eof() != true) 
    {
        filein >> Ma_Mon;
        filein.ignore();
        filein.ignore();
        getline(filein, Ten_Mon, x);
        filein >> Gia;
        filein.ignore();
        filein >> TT;
        filein.ignore();

        if(TT == "Con") Tinh_Trang = false;
        else Tinh_Trang = true;
        Ten_Mon = ChuanHoa(Ten_Mon);

        // Kiem Tra MA va TEN da ton tai chua
        if(FindIndexMa(Ma_Mon) != -1)
        {
            // cout << "\t\t\t Ma Mon An '" << Ma_Mon << "' - Ten Mon An '" << Ten_Mon << "' Da ton tai!" << endl;
            continue;
        }
        else if(FindIndexTen(Ten_Mon) != -1)
            {
                // cout << "\t\t\t Ten Mon An '" << Ten_Mon << "' Da ton tai!" << endl;
                continue;
            }
        MonAn *Mon = new MonAn(Ma_Mon, Ten_Mon, Gia, Tinh_Trang);
        dataMonAn.push_back(Mon);
        (this->LengthM_A)++;
    }
    cout << "\n\t\t\t Doc File thanh cong!" << endl;
    filein.close();
}
// Tim kiem mon an theo MA
int QLMonAn::FindIndexMa(const string &index)
{
    for(int i=0; i<this->LengthM_A; i++)
    {
        if(this->dataMonAn[i]->getMaMon() == index)
            return i;
    }
    return -1;
}
int QLMonAn::FindIndexTen(const string &index)
{
    for(int i=0; i<this->LengthM_A; i++)
    {
        if(this->dataMonAn[i]->getTenMon() == index)
            return i;
    }
    return -1;
}
void QLMonAn::Remove()
{
    this->Show();
    cout << endl << "\t\t\tXoa Theo MA" << endl;
    string Ma_Mon;
    cout << "\t\t\tNhap MA mon an muon xoa: "; cin >> Ma_Mon;
    if(FindIndexMa(Ma_Mon) == -1)
    {
        cout << "\t\t\t Khong tim thay mon an " << endl;
        return;
    }
    else
    {
        this->dataMonAn[FindIndexMa(Ma_Mon)]->TinhTrang = false;
        cout << "\t\t\t Xoa Thanh Cong Mon An" << endl;
    }
}
void QLMonAn::Find()
{
    cout << "\t\t\tTim MON AN theo MA " << endl;
    string Ma_Mon;
    cout << "\t\t\tNhap Ma MON AN: "; cin >> Ma_Mon;
    int n = FindIndexMa(Ma_Mon);
    if(n == -1)
    {
        cout << "\t\t\tMa MON AN khong ton tai!" << endl;
        return;
    } 
    else
    {
        cout << "\t\t\t Mon An Co Ma la: " << Ma_Mon << endl << endl;
        cout << "\t\t\t Ma      Ten                   Gia   Tinh Trang" << endl;
        cout << *this->dataMonAn[n];
    }
}
void QLMonAn::Update()
{
    system("cls");
    cout << "\t\t\t-------------------------------" << endl
         << "\t\t\t0. Thoat" << endl
         << "\t\t\t1. Cap Nhat GIA Mon An" << endl
         << "\t\t\t2. Cap Nhat Tinh Trang Mon An" << endl
         << "\t\t\t------------------------------" << endl;
    int LuaChon;
    cout << "\t\tNhap Lua Chon: "; cin >> LuaChon;
    if(LuaChon == 0)
    {
        return;
    }
    else
    {
        string Ma_Mon;
        cout << "\t\t\tNhap Ma Mon Can UPDATE: "; cin >> Ma_Mon;
        if(FindIndexMa(Ma_Mon) == -1)
        {
            cout << "\t\t\tMa Mon An Khong Ton Tai!" << endl;
            return;
        }
        switch (LuaChon)
        {
        case 1:
        {
            ll newGia;
            cout << "\t\t\tGia Hien Tai Cua Mon An: " << this->dataMonAn[FindIndexMa(Ma_Mon)]->getDonGia() << endl;
            cout << "\t\t\tNhap Gia Moi Cua Mon An: "; cin >> newGia;
            this->dataMonAn[FindIndexMa(Ma_Mon)]->setDonGia(newGia);
            cout << "\t\t\tCap Nhat Gia Mon An Thanh Cong!" << endl;
            break;
        }
        case 2:
        {
            cout << "\t\t\tTinh Trang Cua Mon An: ";
            if(this->dataMonAn[FindIndexMa(Ma_Mon)]->getTinhTrang())
                cout << "Con";
            else 
                cout << "Het";
            cout << "\t\t\tCap Nhat Tinh Trang (1-Con   2-Het): ";
            int Choose; cin >> Choose;
            if(Choose == 1)
                this->dataMonAn[FindIndexMa(Ma_Mon)]->setTinhTrang(true);
            else 
                this->dataMonAn[FindIndexMa(Ma_Mon)]->setTinhTrang(false);
            cout << "\t\t\tCap Nhat Tinh Trang Mon An Thanh Cong!" << endl;
            break;
        }   
        default:
        {
            cout << "\t\t\tLua Chon Khong Hop Le!!" << endl;
            system("pause");
            break;
        }
        }
    }
}
void QLMonAn::Show()
{
    system("cls");
    cout << "\t\t\t DANH SACH MON AN" << endl << endl;
    for(int i=0; i<this->LengthM_A; i++)
    {
        cout << *this->dataMonAn[i] << endl;
    }
}
void QLMonAn::Writef(){
    ofstream fileout;
    fileout.open("DsMonAn.txt");
    if(fileout.is_open() == false)
    {
        cout << "\t\t\tCouldn't open file..." << endl;
    }
    for (int i = 0; i < this->getLengthM_A(); i++)
    {
        // fileout << *dataMonAn[i];
        fileout << dataMonAn[i]->MaMon << " ," << dataMonAn[i]->TenMon << " ," << dataMonAn[i]->DonGia << " ,";
        if(dataMonAn[i]->TinhTrang)
            fileout << "Con" << endl;
        else 
            fileout << "Het" << endl;
    }
    fileout.close();
}
bool up(ll x, ll y)
{
    return (x > y) ? true : false;
}
bool down(ll x, ll y)
{
    return (x < y) ? true : false;
}

void QLMonAn::selectionsortGiaBan(bool (*cmp)(ll,ll))
{
    for(int i = 0; i< this->LengthM_A-1;i++)
    {
        for (int j = i + 1; j < this->LengthM_A; j++)
        {
            if (cmp(dataMonAn[i]->getDonGia(),dataMonAn[j]->getDonGia()))
            {
                swap(dataMonAn[i],dataMonAn[j]);
            }   
        }
    }
}
bool up_s(string x, string y)
{
    return (x > y) ? true : false;
}
void QLMonAn::selectionsortMa()
{
    for(int i = 0; i< this->LengthM_A-1;i++)
    {
        for (int j = i + 1; j < this->LengthM_A; j++)
        {
            if (dataMonAn[i]->getMaMon() > dataMonAn[j]->getMaMon())
            {
                swap(dataMonAn[i],dataMonAn[j]);
            }   
        }
    }
}

void QLMonAn::Sort(){
    system("cls");
    cout << "\n\t\t-------------------------------------------------------";
    cout << "\n\t\t|\t1. Sap xep theo chieu giam cua gia ban\t\t|";
    cout << "\n\t\t|\t2. Sap xep theo chieu tang cua gia ban\t\t|";
    cout << "\n\t\t|\t0. Thoat\t\t\t\t\t|";
    cout << "\n\t\t-------------------------------------------------------" << endl;
    cout << "\n\t\t\t\tNhap lua chon: ";
    int LuaChon; cin >> LuaChon;
    switch(LuaChon){
        case 0:
        {
            break;
        }
        case 1:
        {
            selectionsortGiaBan(down);
            cout << "\t\t\tSap xep thanh cong!" << endl;
            break;
        }
        case 2:
        {
            selectionsortGiaBan(up);
            cout << "\t\t\tSap xep thanh cong!" << endl;
            break;
        }
        default:
        {
            cout << "\t\t\tLua chon khong hop le!";
            break;

        }
    }
}
void QLMonAn::clear()
{
    dataMonAn.clear();
    LengthM_A = 0;
}