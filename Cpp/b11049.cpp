#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
pair<int, int> M[501];
int dp[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> M[i].first >> M[i].second;
    }

    for (int i = 0; i <= N; ++i)
    {
        for (int j = i; j <= N; ++j)
        {
            dp[i][j] = 2147483647;
        }

        dp[i][i] = 0;
    }

    for (int len = 1; len < N; ++len)
    {
        for (int i = 1; i + len <= N; ++i)
        {
            for (int mid = i; mid < i + len; ++mid)
            {
                dp[i][i + len] = min(dp[i][i + len], dp[i][mid] + dp[mid + 1][i + len] + M[i].first * M[mid + 1].first * M[i + len].second);
            }
        }
    }

    cout << dp[1][N] << endl;

    return 0;
}