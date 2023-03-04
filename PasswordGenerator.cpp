#include <iostream>
#include <string> 
#include <stdlib.h>
using namespace std;

string generatorPassword(int count, string base) {
    srand(rand() + time(0));
    int max = strlen(base.c_str());
    string password = "";
    for (int i = 0; i < count; i++)
       password = password + base[rand() % (max)];
    return password;
 }

string mixString(string  text)
{
    srand(rand() + time(0));
    int max = strlen(text.c_str());
    int firstPosition;
    int nextPosition;
    char ch;
    for (int i = 0; i < max; i++)
    {
        firstPosition =rand() % (max);
        nextPosition =rand() % (max);
        ch = text[firstPosition];
        text[firstPosition] = text[nextPosition];
        text[nextPosition] = ch;
    }
    return  text;
}

string generatorPassword(int count, const char* base) {
    srand(rand()+time(0));
    int max = strlen(base);
    string password = "";
    for (int i = 0; i < count; i++)
        password = password + base[rand() % (max)];
    return password;
}



string generatorPassword(int countNumber, int countSpecial, int countUppercase, int countLowercase) {
    string Number = "1234567890";
    string Special = "/!@#$%^&*()_+{}:<>?[];',.";
    string Uppercase = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string Lowercase = "qwertyuiopasdfghjklzxcvbnm";
    string password="";
    password = password + generatorPassword(countNumber, Number);
    password = password + generatorPassword(countSpecial, Special);
    password = password + generatorPassword(countUppercase, Uppercase);
    password = password + generatorPassword(countLowercase, Lowercase);
 
    return mixString(password);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите количество требуемых паролей:";
    int countpass;
    cin >> countpass;
    cout << "Введите количество чисел в пароле:";
    int countNumber;
    cin >> countNumber;
    cout << "Введите количество спец символов в пароле:";
    int countSpecial;
    cin >> countSpecial;
    cout << "Введите количество прописных букв в пароле:";
    int countUppercase;
    cin >> countUppercase;
    cout << "Введите количество строчных букв в пароле:";
    int countLowercase;
    cin >> countLowercase;
    string s = "";
    for (int i = 0; i < countpass; i++)
    {
          cout << generatorPassword(countNumber, countSpecial, countUppercase, countLowercase) << endl;
    }
    
}
