#include "../Headers/Option.h"
#include "../Headers/Admin.h"
#include "../Headers/Password.h"
#include <conio.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "../Headers/Person.h"
#include "../Headers/Console.h"
#include "../Headers/Search.h"

using namespace std;

Adminmenu::Adminmenu()
{
    this->removeItem();
    this->removeItem();
    this->removeItem();
    this->addItem("ADD PHONE RECORD");
    this->addItem("DISPLAY ALL RECORDS");
    this->addItem("REMOVE RECORD");
    this->addItem("SEARCH BY ID");
    this->addItem("SEARCH BY NUMBER");
    this->addItem("SEARCH BY NAME");
    this->addItem("SEARCH BY EMAIL");
    this->addItem("BACK TO MAIN MENU");
}

int Adminmenu::point = 0;

void Adminmenu::printItems()
{
    int f = 1;
    while(f)
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        Console::PrintCenter("#####**************************PHONEBOOK**************************#####", 0);
        for(int i = 0; i < static_cast<int>(_count); i++)
        {
            if(point == i)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                Console::PrintCenter( options[i].GetName(), i+10);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                Console::PrintCenter( options[i].GetName(), i+10);
            }
        }
        int t = 1;
        char ch;
        while(t)
        {
            ch = _getch();
            if(ch == 72)
            {
                point -= 1;
                if(point == -1)
                    point = _count - 1;
                break;
            }
            else if(ch == 80)
            {
                point += 1;
                if(point == static_cast<int>(_count))
                    point = 0;
                break;
            }
            else if(ch == 13)
            {
                this->addButton();
                t = 0;
                f = 0;
            }
        }
        Sleep(110);
    }
    cout << '\n';
}
void Adminmenu::addButton()
{
    fstream file;
    fstream ifile;
    file.open( "database.txt", ios_base::app | ios::in | ios::out);
    ifile.open( "ifile.txt", ios_base::app | ios::in | ios::out);
    switch(point)
    {
    case 0:
    {
        system("cls");
        Persoana pers;
        pers.AddPersoana();
        Console::PrintCenter( "Do you want to return to Admin menu? (y/n)", 17);
        char c;
        cin >> c;
        if(c == 'y' || c == 'Y')
        {
            system("cls");
            Menu *admin = new Adminmenu();
            admin -> printItems();
        }
        else
            exit(0);
        break;
    }
    case 1:
    {
        system("cls");
        Persoana pers;
        int i = 4, ok = 0;
        while(file >> pers)
        {
            if(!ok) Console::printMessage();
            cout << pers;
            ok = 1;
            i++;
        }
        Console::PrintCenter( "Do you want to return to Admin menu? (y/n)", i+2);
        char c;
        cin >> c;
        if(c == 'y' || c == 'Y')
        {
            system("cls");
            Menu *admin = new Adminmenu();
            admin -> printItems();
        }
        else
            exit(0);
        break;
    }
    case 2:
    {
        system("cls");
        Persoana pers;
        pers.Remove();
        file.close();
        ifile.close();
        remove( "database.txt");
        rename( "ifile.txt","database.txt");
        Console::PrintCenter( "Do you want to return to Admin menu? (y/n)", 22);
        char c;
        cin >> c;
        if(c == 'y' || c == 'Y')
        {
            system("cls");
            Adminmenu *admin = new Adminmenu();
            admin -> printItems();
        }
        else
            exit(0);
        break;
    }
    case 3:
    {
        system("cls");
        int i = 15;
        Search::ById(i);
        Console::PrintCenter( "Do you want to return to Admin menu? (y/n)", i+2);
        char c;
        cin >> c;
        if(c == 'y' || c == 'Y')
        {
            system("cls");
            Adminmenu *admin = new Adminmenu();
            admin -> printItems();
        }
        else
            exit(0);
        break;
    }
    case 4:
    {
        system("cls");
        int i = 15;
        Search::ByNumber(i);
        Console::PrintCenter( "Do you want to return to User menu? (y/n)", i+2);
        char c;
        cin >> c;
        if(c == 'y' || c == 'Y')
        {
            system("cls");
            Adminmenu *admin = new Adminmenu();
            admin -> printItems();
        }
        else
            exit(0);
        break;
    }
    case 5:
    {
        system("cls");
        int i = 15;
        Search::ByName(i);
        Console::PrintCenter( "Do you want to return to User menu? (y/n)", i+2);
        char c;
        cin >> c;
        if(c == 'y' || c == 'Y')
        {
            system("cls");
            Adminmenu *admin = new Adminmenu();
            admin -> printItems();
        }
        else
            exit(0);
        break;
    }
    case 6:
    {
        system("cls");
        int i = 15;
        Search::ByEmail(i);
        Console::PrintCenter( "Do you want to return to Admin menu? (y/n)", i+2);
        char c;
        cin >> c;
        if(c == 'y' || c == 'Y')
        {
            system("cls");
            Adminmenu *admin = new Adminmenu();
            admin -> printItems();
        }
        else
            exit(0);
        break;
    }
    case 7:
    {
        system("cls");
        Menu menu;
        menu.printItems();
        break;
    }
    }
}
Adminmenu::~Adminmenu()
{
    if(options != NULL)
    {
        delete []options;
    }
}
