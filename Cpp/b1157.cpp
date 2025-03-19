#include <iostream>
#include <string>
#include <array>

using namespace std;

int main()
{
    string input;
    cin >> input;

    array<int, 26> count;
    for (int i=0; i<26; ++i)
    {
        count[i] = 0;
    }

    for (const auto ch : input)
    {
        if (ch > 'Z')
        {
            count[ch-'a'] += 1;
        }
        else
        {
            count[ch-'A'] += 1;
        }
    }

    int mostCount = 0;
    char mostChar = '?';
    for (char ch = 'A'; ch <= 'Z'; ++ch)
    {
        if (count[ch-'A'] == mostCount)
        {
            mostChar = '?';
        }
        else if (count[ch-'A'] > mostCount)
        {
            mostCount = count[ch-'A'];
            mostChar = ch;
        }
    }

    cout << mostChar << endl;

    return 0;
}