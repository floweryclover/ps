#include <iostream>
#include <vector>
#include <limits>

using namespace std;

constexpr int Infinite = numeric_limits<int>::max();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> costs;
    costs.resize(N);
    for (int i = 0; i < N; ++i)
    {
        costs[i].resize(N);
        for (int j = 0; j < N; ++j)
        {
            cin >> costs[i][j];
        }
    }

    vector<vector<int>> dp;
    dp.resize(N);
    for (int city = 0; city < N; ++city)
    {
        dp[city].resize((1 << N), Infinite);
        dp[city][(1 << city) | 1] = costs[0][city];
    }

    for (int size = 2; size <= N; ++size)
    {
        for (int bit = 0; bit <= (1 << N) - 1; ++bit)
        {
            int sizeCount = 0;
            for (int bitCheck = 0; bitCheck < N; ++bitCheck)
            {
                if (bit & (1 << bitCheck))
                {
                    sizeCount += 1;
                }
            }
            if (sizeCount != size)
            {
                continue;
            }

            for (int curCity = 1; curCity < N; ++curCity)
            {
                for (int prevCity = 0; prevCity < N; ++prevCity)
                {
                    if (((bit & (1 << curCity))  == 0) ||
                        ((bit & (1 << prevCity)) == 0) ||
                        dp[prevCity][bit & ~(1 << curCity)] == Infinite)
                    {
                        continue;
                    }

                    const int cost = costs[prevCity][curCity];
                    dp[curCity][bit] = cost == 0 ? Infinite
                                                : min(dp[curCity][bit], dp[prevCity][bit & ~(1 << curCity)] + costs[prevCity][curCity]);
                }
            }
        }
    }

    int minimum = Infinite;
    for (int city = 1; city < N; ++city)
    {
        const int value = dp[city][((1 << N) - 1)];
        if (value == Infinite || costs[city][0] == 0)
        {
            continue;
        }

        minimum = min(minimum, value + costs[city][0]);
    }

    cout << minimum << endl;
    
    return 0;
}