#include <iostream>

using namespace std;

using ULL = unsigned long long;

int N;
ULL C[250001];
ULL dp[2][250001][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> C[i];
    }

    dp[0][1][0] = C[1];
    dp[0][1][1] = 0;
    dp[1][1][0] = C[1];
    dp[1][1][1] = 1;
    dp[0][0][0] = dp[0][0][1] = dp[1][0][0] = dp[1][0][1] = 0;
    for (int initial = 0; initial <= 1; ++initial)
    {
        for (int i = 2; i < N; ++i)
        {
            dp[initial][i][1] = dp[initial][i - 1][0] + 1;
            dp[initial][i][0] = max(dp[initial][i - 1][0], dp[initial][i - 1][1]) + C[i];
        }
    }

    dp[0][N][0] = max(dp[0][N - 1][0], dp[0][N - 1][1]) + C[N];
    dp[0][N][1] = dp[0][N - 1][0] + 1;
    dp[1][N][0] = max(dp[1][N - 1][0], dp[1][N - 1][1]) + C[N];
    dp[1][N][1] = 0;

    cout << max(max(dp[0][N][0], dp[0][N][1]), dp[1][N][0]) << endl;

    return 0;
}