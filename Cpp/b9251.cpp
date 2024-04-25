#include <iostream>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b, lcs;
    cin >> a >> b;

    array<array<int, 1001>, 1001> dp;
    dp[0][0] = dp[1][0] = dp[0][1] = 0;
    for (int i=1; i<=a.length(); i++)
    {
        for (int j=1; j<=b.length(); j++)
        {
            if (a[i-1]==b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[a.length()][b.length()] << endl;
    return 0;
}