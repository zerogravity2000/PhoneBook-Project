#include "../Headers/Object.h"
#include <string.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../Headers/Password.h"
#include "../Headers/Admin.h"
#include "../Headers/Console.h"
#include "../Headers/User.h"
#include "../Headers/Username.h"

//Add menu items
int Level::point = 0;

Level::Level() : objects(NULL), _count(0)
{
    this->AddItem("ADMIN");
    this->AddItem("USER");
    this->AddItem("EXIT");
}
Level::~Level()
{
    if(objects != NULL)
    {
        delete []objects;
    }
}

void Level::AddItem(const string& name)
{
    OBJECT obj(name);
    if(objects == NULL)
    {
        objects = new OBJECT[1];
        objects[0] = obj;
        _count++;
    }
    else
    {
        OBJECT* temp = objects;
        objects = new OBJECT[_count + 1];
        for(int i=0; i < (int)_count; i++)
            objects[i] = temp[i];
        objects[_count] = obj;
        _count++;
        delete []temp;
    }
}

void Level::RemoveItem()
{
    OBJECT* temp=objects;
    objects = new OBJECT[_count - 1];
    for(int i = 0; i < (int)_count-1; i++)
        objects[i] = temp[i];
    _count--;
    delete []temp;
}

void Level::PrintItems()
{
    int f=1;
    while(f)
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        cout<<"#####******************************PHONEBOOK******************************#####"<<endl;
        for(int i=0; i < (int)_count; i++)
        {
            if(point == i)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
                Console::gotoxy(37,i+10);
                cout<<objects[i].GetName();
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            }
            else
            {
                Console::gotoxy(37,i+10);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                cout<<objects[i].GetName();
            }
        }
        int t = 1;
        char ch;
        while(t)
        {
            ch=_getch();
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
                if(point == (int)_count)
                    point = 0;
                break;
            }
            else if(ch == 13)
            {
                this->AddButton();
                t = 0;
                f = 0;
            }
        }
        Sleep(110);
    }
    cout << '\n';
}

void Level::AddButton()
{
    switch(point)
    {
    case 0:
    {
        system("cls");
        Username user;
        user.EnterUser();
        Password pass;
        pass.AddPassword();
        if(user.ReturnUser() and pass.ReturnPass())
        {
            system("cls");
            Console::gotoxy(33,10);
            cout<<"Successful authentication.";
            Console::gotoxy(33,14);
            cout<<"Do you want to continue? Press any key: ";
            _getch();
            system("cls");
            Adminmenu admin;
            admin.PrintItems();
        }
        else

        {
            Console::gotoxy(18,10);
            cout<<"Incorect password or username. Return to main menu.(y / n) ";
            char c;
            cin>>c;
            if(c=='y' || c=='Y')
            {
                system("cls");
                Level level;
                level.PrintItems();
            }
            else
                exit(0);
        }
        break;
    }
    case 1:
    {
        point=0;
        system("cls");
        User user;
        user.PrintItems();
        break;
    }
    case 2:
        {
           exit(0);
           break;
        }

    }
}
