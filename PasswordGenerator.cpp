#include <iostream>
#include <string> 
#include <stdlib.h>
using namespace std;

string generatorPassword(int count, string base) {
    srand(rand() + time(0));
    int max = strlen(base.c_str())+1;
    string password = "";
    for (int i = 0; i < count; i++)
       password = password + base[rand() % (max)];
    return password;
 }

string generatorPassword(int count, const char* base) {
    srand(rand()+time(0));
    int max = strlen(base) + 1;
    string password = "";
    for (int i = 0; i < count; i++)
        password = password + base[rand() % (max)];
    return password;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    const char* base= "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890!@#$%^&*()_+{}:<>?[];',./";
    int countpass;
    int countchar;
    cout << "Введите количество требуемых паролей:";
    cin >> countpass;
    cout << "Введите количество символов в пароле:";
    cin >> countchar;
    for (int i = 0; i < countpass; i++)
    {
        cout << generatorPassword(countchar, base) << endl;
    }
    
}
