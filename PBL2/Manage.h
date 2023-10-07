#pragma once
#include "QLMonAn.h"
#include "QLHoaDon.h"
void Manage(QLMonAn &ql_Mon)
{
    system("cls");
    cout    << "\n\t\t\t================================================="
            << "\n\t\t\t|             MENU QUAN LY NHA HANG             |"
            << "\n\n\t\t|                   QL MON AN                   |"
            << "\n\t\t\t=================================================" << endl;
    int choose = 1;
    do
    {
        ql_Mon.Readf();
        ql_Mon.selectionsortMa();
        system("cls");
        cout << "\n\t\t\t================================================="
             << "\n\t\t\t|              MENU QUAN LY MON AN              |"
             << "\n\t\t\t|    1. Doc file danh sach mon an               |"
             << "\n\t\t\t|    2. Them mon an                             |"
             << "\n\t\t\t|    3. Xoa 1 mon an                            |"
             << "\n\t\t\t|    4. Tim thong tin mon an                    |"
             << "\n\t\t\t|    5. Thay doi thong tin mon an               |"
             << "\n\t\t\t|    6. Sap xep mon an                          |"
             << "\n\t\t\t|    7. In danh sach mon an                     |"
             << "\n\t\t\t|    8. Xuat file danh sach mon an              |"
             << "\n\t\t\t|    0. Thoat khoi chuong trinh                 |"
             << "\n\t\t\t=================================================";
        cout << "\n\t\t\tNhap Lua Chon: " ; 
        cin >> choose;
        switch (choose)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            ql_Mon.Readf();
            ql_Mon.selectionsortMa();
            cout << "--------------------------------------------";
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            ql_Mon.Show();
            ql_Mon.Insert();
            ql_Mon.selectionsortMa();
            ql_Mon.Writef();
            cout << "--------------------------------------------";
            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            ql_Mon.Show();
            ql_Mon.Remove();
            cout << "---------------------------------------------";
            system("pause");
            break;
        }
        case 4:
        {
            system("cls");
            ql_Mon.Show();
            ql_Mon.Find();
            cout << "---------------------------------------------";
            system("pause");
            break;
        }
        case 5:
        {
            system("cls");
            ql_Mon.Show();
            ql_Mon.Update();
            cout << "----------------------------------------------";
            system("pause");
            break;
        }
        case 6:
        {
            ql_Mon.Sort();
            cout << "------------------------------------------------";
            system("pause");
            ql_Mon.Show();
            cout << "------------------------------------------------";
            system("pause");
            break;
        }
        case 7:
        {
            system("cls");
            ql_Mon.Show();  
            cout << "------------------------------------------------";
            system("pause");
            break;
        }
        case 8:
        {
            ql_Mon.selectionsortMa();
            ql_Mon.Writef();
            cout << "\t\t\tGhi vao file thanh cong!" << endl;
            cout << "-------------------------------------------------";
            system("pause");
            break;
        }
        default:
            break;
        }
    } while (choose != 0);
    
}

void InvoiceManage(QLHoaDon &ql_hd, QLMonAn &ql_mon)
{
    int choose;
    do
    {
        system("cls");
        cout << "\n\t\t\t=================================================="
             << "\n\t\t\t|             MENU QUAN LY HOA DON               |"
             << "\n\t\t\t|\t1. Tao hoa don                           |"
             << "\n\t\t\t|\t2. Tim thong tin hoa don                 |"
             << "\n\t\t\t|\t3. In ra danh sach hoa don               |"
             << "\n\t\t\t|\t0. Thoat                                 |"
             << "\n\t\t\t================================================="
             << "\n\t\t\t\tNhap lua chon: ";
        cin >> choose;

        switch (choose)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            ql_hd.Insert(ql_mon);
            cout << "--------------------------------------------------";
            system("pause");
            break;
        }
        case 2:
        {
            ql_hd.Find(ql_mon);
            cout << "--------------------------------------------------";
            system("pause");
            break;
        }
        case 3:
        {
            ql_hd.Show(ql_mon);
            cout << "--------------------------------------------------";
            system("pause");
            break;
        }
        default:
        {
            cout << "\n\t\tLua chon khong hop le! " << endl;
            cout << "---------------------------------------------------";
            system("pause");
            break;
        }
        }
    } while (choose!=0);
}