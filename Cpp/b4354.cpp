#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true)
    {
        char input[1'000'001];
        cin >> input;
        if (input[0] == '.')
        {
            break;
        }

        int Pi[1'000'000];
        const int len = strlen(input);
        int j = 0;
        for (int i = 1; i < len; ++i)
        {
            while (j > 0 && input[j] != input[i])
            {
                j = Pi[j - 1];
            }
            if (input[j] == input[i])
            {
                ++j;
                Pi[i] = j;
            }
        }

        const int a = len - Pi[len - 1];
        
        bool matches = true;
        for (int i = 0; i < a; ++i)
        {
            if (input[len - a + i] != input[i])
            {
                matches = false;
                break;
            }
        }

        if (matches)
        {
            cout << len / a << "\n";
        }
        else
        {
            cout << 1 << "\n";
        }
    }

    return 0;
}