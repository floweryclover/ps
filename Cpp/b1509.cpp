#include <iostream>
#include <cstring>

using namespace std;

bool palindrome[2501][2501]; // pos, len
string str;
bool flag[2501];
int dp[2501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> str;

    memset(palindrome, 0, sizeof(palindrome));

    for (int i = 1; i <= str.length(); ++i)
    {
        palindrome[i][1] = true;
    }

    for (int i = 2; i <= str.length(); ++i)
    {
        palindrome[i][2] = str[i - 2] == str[i-1];
    }

    for (int len = 3; len <= str.length(); ++len)
    {
        for (int i = len; i <= str.length(); ++i)
        {
            palindrome[i][len] = palindrome[i - 1][len - 2] && str[i - len] == str[i-1];
        }
    }

    dp[0] = 0;
    for (int i = 1; i <= str.length(); ++i)
    {
        dp[i] = i;
        for (int len = 1; len <= str.length(); ++len)
        {
            if (i - len >= 0 && palindrome[i][len])
            {
                dp[i] = min(dp[i], dp[i - len] + 1);
            }
        }
    }

    cout << dp[str.length()] << endl;

    return 0;
}