#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

array<char, 15> characters;
vector<string> passwords;

int l, c;

void GenerateAllPossiblePasswords(int index, array<char, 15> selectedCharacters, int length)
{
    if (index >= c && length < l)
        return;

    if (length == l)
    {
        int vowels = 0;
        int consonants = 0;
        for (int i=0; i<length; i++)
        {
            switch (selectedCharacters[i])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowels++;
                    break;
                default:
                    consonants++;
                    break;
            }
        }
        if (vowels < 1 || consonants < 2)
            return;
        
        passwords.push_back(string(selectedCharacters.begin(), selectedCharacters.begin()+length));
        return;
    }
        
    GenerateAllPossiblePasswords(index+1, selectedCharacters, length);
    selectedCharacters[length] = characters[index];
    GenerateAllPossiblePasswords(index+1, selectedCharacters, length+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> l >> c;

    for (int i = 0; i < c; i++)
        cin >> characters[i];

    sort(characters.begin(), characters.begin()+c);

    GenerateAllPossiblePasswords(0, {}, 0);

    sort(passwords.begin(), passwords.end());
    for (const auto& password : passwords)
        cout << password << endl;

    return 0;
}