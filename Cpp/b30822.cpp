#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int _n;
    cin >> _n;

    string str;
    cin >> str;

    int minCount = 1001;
    int charCount = count(str.begin(), str.end(), 'u');
    minCount = minCount > charCount ? charCount : minCount;

    charCount = count(str.begin(), str.end(), 'o');
    minCount = minCount > charCount ? charCount : minCount;

    charCount = count(str.begin(), str.end(), 's');
    minCount = minCount > charCount ? charCount : minCount;

    charCount = count(str.begin(), str.end(), 'p');
    minCount = minCount > charCount ? charCount : minCount;

    charCount = count(str.begin(), str.end(), 'c');
    minCount = minCount > charCount ? charCount : minCount;

    cout << minCount << endl;

    return 0;
}