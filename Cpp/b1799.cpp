#include <iostream>
#include <cstring>

using namespace std;

int N;
int dp[20][1 << 20];
int board[11][11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int y = 1; y <= N; ++y)
    {
        for (int x = 1; x <= N; ++x)
        {
            cin >> board[y][x];
        }
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    int maximum = 0;
    for (int i = 1; i < 2 * N; ++i)
    {
        for (int bit = 0; bit < (1 << (N * 2 - 1)); ++bit)
        {
            dp[i][bit] = dp[i - 1][bit];
            maximum = max(maximum, dp[i][bit]);

            for (int place = 0; place < 2 * N - 1; ++place)
            {
                const int mask = (1 << place);
                const int py = N - (place + 1) / 2 + (i - ((N & 1) ? 0 : 1)) / 2 - (N - 1) / 2;
                const int px = 1 + (place / 2)     + (i - ((N & 1) ? 0 : 1)) / 2 - (N - 1) / 2;
                if (((i + (N & 1)) & 1) != (place & 1) || (bit & mask) == 0)
                {
                    continue;
                }

                if (py < 1 || py > N || px < 1 || px > N || board[py][px] == 0 || dp[i - 1][bit & ~(mask)] == -1)
                {
                    continue;
                }

                dp[i][bit] = max(dp[i][bit], dp[i - 1][bit & ~(mask)] + 1);
                maximum = max(maximum, dp[i][bit]);
            }
        }
    }

    cout << maximum << endl;

    return 0;
}