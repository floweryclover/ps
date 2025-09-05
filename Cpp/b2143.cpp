#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> aSums;
int n, m, T;

int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    cin >> n;

    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int input;
        cin >> input;
        dp[i] = dp[i - 1] + input;
    }

    aSums.reserve(n + 1);
    for (int len = 1; len <= n; ++len)
    {
        for (int i = len; i <= n; ++i)
        {
            aSums.push_back(dp[i] - dp[i - len]);
        }
    }
    sort(aSums.begin(), aSums.end());

    unsigned long long count = 0;
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        int input;
        cin >> input;
        dp[i] = dp[i - 1] + input;
    }

    for (int len = 1; len <= m; ++len)
    {
        for (int i = len; i <= m; ++i)
        {
            const int toFind = T - dp[i] + dp[i - len];
            count += upper_bound(aSums.begin(), aSums.end(), toFind) - lower_bound(aSums.begin(), aSums.end(), toFind);
        }
    } 

    cout << count << endl;

    return 0;
}