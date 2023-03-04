#include <iostream>
#include <string> 
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;


const string Number = "1234567890";
const string Special = "/!@#$%^&*()_+{}:<>?[];',.";
const string Uppercase = "QWERTYUIOPASDFGHJKLZXCVBNM";
const string Lowercase = "qwertyuiopasdfghjklzxcvbnm";


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
    cout << "Введите имя файла:";
    string fl;
    cin >> fl;
    std::ofstream out(fl, std::ios::app);
    for (int i = 0; i < countpass; i++)
    {
        if (out.is_open())
        {
            out << generatorPassword(countNumber, countSpecial, countUppercase, countLowercase) << std::endl;
        }
    }
    out.close();
    cout << "Файл сохранен!";
    
}
