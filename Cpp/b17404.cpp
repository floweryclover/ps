#include <iostream>
#include <cstring>

using namespace std;

int N;
int costs[1001][3];
int dp[1001][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> costs[i][j];
        }
    }
    memset(dp, 0, sizeof(dp));
    int minimum = 1000000;
    for (int initialColor = 0; initialColor < 3; ++initialColor)
    {
        for (int color = 0; color < 3; ++color)
        {
            dp[1][color] = color == initialColor ? costs[1][color] : 1000000; 
        }
        for (int i = 2; i <= N; ++i)
        {
            for (int color = 0; color < 3; ++color)
            {
                dp[i][color] = min(dp[i - 1][(color + 2) % 3] + costs[i][color], 
                                    dp[i - 1][(color + 1) % 3] + costs[i][color]);
            }
        }

        for (int color = 0; color < 3; ++color)
        {
            if (color == initialColor)
            {
                continue;
            }
            minimum = min(minimum, dp[N][color]);
        }
    }

    cout << minimum << endl;

    return 0;
}