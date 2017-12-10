#ifndef USERNAME_H_INCLUDED
#define USERNAME_H_INCLUDED

#include "../Interfaces/IUser.h"
#include <string>
using namespace std;

class User: public IUser
{
    string username;
    string password;
public:
    User();
    void SetUsername(string);
    void SetPassword(string);
    string GetPassword();
    string GetUsername();
    ~User();
    friend istream& operator>>(istream& stream, User& user);
};

#endif // USERNAME_H_INCLUDED