#include "QLMonAn.h"
#include "QLHoaDon.h"
#include "Manage.h"
#include "PASS.h"

int main()
{
    QLMonAn Quanly_MonAn;
    QLHoaDon Quanly_HoaDon;
    int choose1;
    do
    {
        system("cls");
        cout << "\n\t\t\t================================================="
             << "\n\t\t\t|            PHAN MEM QUAN LY NHA HANG          |"
             << "\n\t\t\t|    Ban la:                                    |"
             << "\n\t\t\t|    1. Admin                                   |"
             << "\n\t\t\t|    2. Nhan vien                               |"
             << "\n\t\t\t|    0. Thoat                                   |"
             << "\n\t\t\t=================================================";
        cout << "\n\t\t\tNhap lua chon: ";
        cin >> choose1;
        if(choose1 == 1)
        {
            string input;
            int check = 1;
            input = getPass("\t\t\tNhap mk su dung chuong trinh: ");
            while (input != PASS)
            {
                cout << "\n\t\t\tSai mk. Nhap lai!" << endl;
                cout << "\n\t\t\tBan co muon tiep tuc (c/k): ";
                char x;
                cin >> x;
                if (x == 'c')
                    input = getPass("\t\t\t\t\t\t\tNhap mk: ");
                else
                {
                    check = 0;
                    break;
                }
            }
        
            if(check == 1)
            {
                int choose2 = 1;
                do
                {
                    system("cls");
                    cout << "\n\t\t\t================================================="
                    << "\n\t\t\t|           PHAN MEM QUAN LY NHA HANG           |"
                    << "\n\t\t\t|    1. Thao tac voi mon an                     |"
                    << "\n\t\t\t|    2. Thao tac voi hoa don                    |"
                    << "\n\t\t\t|    3. Doi mat khau                            |"
                    << "\n\t\t\t|    0. Thoat                                   |"
                    << "\n\t\t\t=================================================";
                    cout << "\n\t\t\tNhap lua chon: ";
                    cin >> choose2;
                    switch (choose2)
                    {
                    case 0:
                        break;
                    case 1:
                    {
                        Manage(Quanly_MonAn);
                        break;
                    }   
                    case 2:
                    {
                        Quanly_MonAn.Readf();
                        InvoiceManage(Quanly_HoaDon, Quanly_MonAn);
                        break;
                    }
                    case 3:
                    {
                        cout << "\n\t\t\tMat khau hien tai: " << PASS << endl;
                        string newpass;
                        cout << "\n\t\t\tNhap mat khau moi: ";
                        cin.ignore();
                        getline(cin, PASS);
                        cout << "\n\t\t\tDoi mat khau thanh cong!" << endl;
                        break;
                    }
                    default:
                    {
                        cout << "\n\t\t\tLua chon khong hop le!" << endl;
                        cout << "\t\t\t=========================";
                        system("pause");
                        break;
                    }
                    }
                } while (choose2 !=0);
            }
            else
                choose1 = 1;
    }
    else if(choose1 == 2)
    {
        // Quanly_MonAn.clear();
        int choose2 = 1;
                do
                {
                    system("cls");
                    cout << "\n\t\t\t=============================================="
                    << "\n\t\t\t|          Pham mem quan ly nha hang         |"
                    << "\n\t\t\t|     1. Danh sach mon an                    |"
                    << "\n\t\t\t|     2. Thao tac voi hoa don                |"
                    << "\n\t\t\t|     0. Thoat                               |"
                    << "\n\t\t\t==============================================";
                    cout << "\n\t\t\tNhap lua chon: ";
                    cin >> choose2;
                    switch (choose2)
                    {
                    case 0:
                        break;
                    case 1:
                    {
                        Quanly_MonAn.Readf();
                        Quanly_MonAn.Show();
                        system("pause");
                        
                        break;
                    }
                    case 2:
                    {
                        InvoiceManage(Quanly_HoaDon, Quanly_MonAn);
                        break;
                    }
                    default:
                    {
                        cout << "\n\t\t\tLua chon khong hop le!" << endl;
                        cout << "\t\t\t=========================";
                        system("pause");
                        break;
                    }
                    }
                } while (choose2 !=0);
        }
    } while (choose1 != 0);
    
}   