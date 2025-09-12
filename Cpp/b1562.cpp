#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;

vector<vector<vector<int>>> dp;

constexpr int Div = 1'000'000'000;

void Sum(int& left, const int right)
{
    left = (left % Div + right % Div) % Div;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < 101; ++i)
    {
        dp.emplace_back();
        for (int j = 0; j < 10; ++j)
        {
            dp[i].emplace_back();
            dp[i][j].resize(1 << 10);
        }
    }

    for (int num = 1; num <= 9; ++num)
    {
        dp[1][num][(1 << num)] = 1;
    }

    for (int i = 2; i <= N; ++i)
    {
        for (int num = 0; num <= 9; ++num)
        {
            for (int bit = 1; bit < (1 << 10); ++bit)
            {
                if ((bit & (1 << num)) == 0)
                {
                    continue;
                }

                if (num - 1 >= 0)
                {
                    Sum(dp[i][num][bit], dp[i - 1][num - 1][bit]);
                    Sum(dp[i][num][bit], dp[i - 1][num - 1][bit & ~(1 << num)]);
                }

                if (num + 1 <= 9)
                {
                    Sum(dp[i][num][bit], dp[i - 1][num + 1][bit]);
                    Sum(dp[i][num][bit], dp[i - 1][num + 1][bit & ~(1 << num)]);
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; ++i)
    {
        sum = (sum % Div + dp[N][i][(1 << 10) - 1] % Div) % Div;
    }
    cout << sum << endl;

    return 0;
}