#include <iostream>
#include <Windows.h>
#include <string>
#include "..\DynamicLib\Header.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);

    HINSTANCE load;
    
    load = LoadLibrary(L"DynamicLib.dll");

    typedef bool (*checkletters) (char, string);

    checkletters CheckLetters;
    CheckLetters = (checkletters)GetProcAddress(load, "CheckLetters");

    int oper;
    string str;
    char letter;
    do
    {
        cout << "1. Проверка символа\n 2. Выход";
        cin >> oper;
        switch (oper)
        {
        case 1: 
            cout << "Введите строку: ";
            cin >> str;
            cout << "Введите символ: ";
            cin >> letter;
        case 2:
            break;
        default:
            cout << "\nНеверное действие!\n";
            break;
        }
    } while (oper != 2);

    cout << CheckLetters(letter, str);

    FreeLibrary(load);
}