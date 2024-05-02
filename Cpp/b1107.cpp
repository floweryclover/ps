#include <iostream>
#include <array>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    array<bool, 10> brokenKeys;
    for (int i=0; i<10; i++)
        brokenKeys[i] = false;
    
    for (int i=0; i<m; i++)
    {
        int key;
        cin >> key;
        brokenKeys[key] = true;
    }

    int minimum = 99999999;
    for (int directChannel=0; directChannel<=1000000; directChannel++)
    {
        bool isValid = true;
        int digitCount = 0;
        string numberString = to_string(directChannel);
        for (char ch : numberString)
        {
            if (brokenKeys[ch - '0'])
            {
                isValid = false;
            }
            digitCount++;
        }

        if (!isValid)
            continue;

        minimum = min(minimum, digitCount + abs(directChannel - n));
    }

    minimum = min(minimum, abs(n - 100));

    cout << minimum << endl;

    return 0;
}