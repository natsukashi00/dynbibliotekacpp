#include <iostream>
#include <string>
using namespace std;

__declspec(dllexport) bool CheckLetters(char letter, string str)
{
    int count = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == letter)
        {
            count++;
        }
    }

    if (count == 0)
    {
        cout << "Буква " << letter << " не встречается в слове '" << str << "'" << endl;
        return false;
    }
    else
    {
        cout << "Буква '" << letter << "' встречается " << count << " раз в слове '" << str << "'" << endl;
        return true;
    }
}