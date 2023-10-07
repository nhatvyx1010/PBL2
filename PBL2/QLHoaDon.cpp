#include "QLHoaDon.h"

QLHoaDon::QLHoaDon()
{
    this->lengthHoaDon = 0;
    this->lengthDate = 0;
}
QLHoaDon::~QLHoaDon()
{

}
// get set
int QLHoaDon::getLengthHoaDon()
{
    return this->lengthHoaDon;
}
void QLHoaDon::setLengthHoaDon(int len)
{
    this->lengthHoaDon = len;
}
//
void QLHoaDon::Insert(QLMonAn& Mon)
{
    HoaDon *hd = new HoaDon;
    hd->Input(Mon, hd->getMa_HoaDon());
    this->dataHoaDon.push_back(hd);
    
    if(lengthHoaDon==0)
    {
        Date *d = new Date(hd->getNgay_Ban());
        dataDate.push_back(d);
        lengthDate++;
    }
    else
    {
        int x=0;
        for(int i=0; i<lengthHoaDon; i++)
        {
            if(hd->getNgay_Ban() == dataHoaDon[i]->getNgay_Ban())
                x=1;
        }
        if(x==0)
        {
            Date *d = new Date(hd->getNgay_Ban());
            dataDate.push_back(d);
            lengthDate++;
        }
    }
    
    
    this->lengthHoaDon++;
}
int QLHoaDon::FindIndexMaHD(const int Ma)
{
    for(int i=0; i<this->lengthHoaDon; i++)
    {
        if(dataHoaDon[i]->getMa_HoaDon() == Ma)
        {
            return i;
        }
    }
    return -1;
}
void QLHoaDon::Find(QLMonAn &Mon)
{
    if(this->lengthHoaDon == 0)
        cout << "\t\t\tDanh sach hoa don rong!" << endl;
    else
    {
        cout << "\t\t\tDanh sach ngay ban: \n";
        for(int i=0; i<this->lengthDate; i++)
        {
            cout << "\t\t\t" << i+1 << ": ";
            this->dataDate[i]->Output();
        }


        Date newDate; int x = -1;
        cout << "\t\t\tNhap Ngay Ban Can Tim Kiem: \n"; newDate.Input();
        for(int i = 0; i < lengthHoaDon; i++)
        {
            if(dataHoaDon[i]->getNgay_Ban() == newDate)
            {
                int n = FindIndexMaHD(dataHoaDon[i]->getMa_HoaDon());
                dataHoaDon[n]->Output(Mon);
                x = 0;
            }
        }
        if(x==-1)
        {
            cout << "\t\t\tKhong tim thay du lieu ngay!"<< endl;
        }
    }
}

void QLHoaDon::Remove()
{
    int maHD;
    cout << "\t\t\tNhap ma hoa don: ";
    cin >> maHD;
    int tmp = FindIndexMaHD(maHD);
    if (tmp == -1)
    {
        cout << "\t\t\tMa khong ton tai!" << endl;
        return;
    }
    else
    {
        dataHoaDon.erase(tmp);
        this->lengthHoaDon--;
        cout << "\t\t\tXoa thanh cong!" << endl;
    }
}
void QLHoaDon::Show(QLMonAn& Mon){
    cout << "\n\t\t\t\t\tDANH SACH CAC HOA DON" << endl;
    for (int i = 0; i<this->lengthHoaDon; i++){
        cout << "\t\t\tChi tiet hoa don thu " << i + 1;
        dataHoaDon[i]->Output(Mon);
        cout << "\n\n";
    }
}