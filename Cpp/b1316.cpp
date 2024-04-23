#include <iostream>
#include <string>
#include <array>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int groupWords = 0;
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        bool isGroupWord = true;;
        string input;
        array<bool, 26> alphabetAppeared;
        
        cin >> input;
        memset(alphabetAppeared.data(), 0, 1*26);

        alphabetAppeared[input[0] - 'a'] = true;
        for (int j=1; j<input.length(); j++)
        {
            char currentAlphabet = input[j];
            char prevAlphabet = input[j-1];
            if (currentAlphabet != prevAlphabet)
            {
                if (alphabetAppeared[currentAlphabet - 'a'])
                {
                    isGroupWord = false;
                    break;
                }
                alphabetAppeared[currentAlphabet - 'a'] = true;
            }
        }
        
        if (isGroupWord)
            groupWords++;
    }
    cout << groupWords << endl;

    return 0;
}