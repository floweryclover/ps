#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int nums[2000];
bool dp[2000][2000];

void Dp()
{
    for (int i = 0; i < N; ++i)
    {
        dp[i][i] = true;
    }

    for (int i = 0; i < N - 1; ++i)
    {
        dp[i][i + 1] = nums[i] == nums[i + 1];
    }

    for (int len = 3; len <= N; ++len)
    {
        for (int i = 0; i + len - 1 < N; ++i)
        {
            dp[i][i + len - 1] = dp[i + 1][i + len - 2] && nums[i] == nums[i + len - 1];
        }
    }
}

int IsPalindrome(const int S, const int E)
{
    return dp[S-1][E - 1] ? 1 : 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }
    Dp();

    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int S, E;
        cin >> S >> E;
        cout << IsPalindrome(S, E) << "\n";
    }

    return 0;
}