#include <iostream>
#include <cstring>

using namespace std;

string str;
int counts[26];

bool MakePalindrome()
{
    int left = 0;
    int right = str.length() - 1;
    while (left < right)
    {
        char alphabet = '\0';
        for (int i = 0; i < 26; ++i)
        {
            if (counts[i] >= 2)
            {
                counts[i] -= 2;
                alphabet = 'A' + i;
                break;
            }
        }

        if (alphabet == '\0')
        {
            return false;
        }

        str[left] = str[right] = alphabet;

        ++left;
        --right;
    }

    if (left == right)
    {
        char alphabet = '\0';
        for (int i = 0; i < 26; ++i)
        {
            if (counts[i] > 0)
            {
                alphabet = 'A' + i;
                break;
            }
        }

        str[left] = alphabet;
    }

    return true;
}

int main()
{
    memset(counts, 0, sizeof(counts));

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> str;

    for (const char alphabet : str)
    {
        counts[alphabet - 'A'] += 1;
    }

    if (MakePalindrome())
    {
        cout << str << endl;
    }
    else
    {
        cout << "I\'m Sorry Hansoo" << endl;
    }

    return 0;
}