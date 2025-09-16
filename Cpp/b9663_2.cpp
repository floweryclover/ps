#include <iostream>
#include <cstring>

using namespace std;

int N;
bool board[16][15][15];
pair<int, int> dir[] = { { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 } };

int Solve(const int cur, const int count)
{
    if (cur == N)
    {
        return 1;
    }

    int sum = 0;
    for (int i = 0; i < N; ++i)
    {
        if (board[cur][cur][i])
        {
            continue;
        }

        memcpy(board[cur + 1], board[cur], sizeof(board[cur]));
        for (int range = 0; range <= N; ++range)
        {
            for (const auto [dy, dx] : dir)
            {
                const int py = cur + dy * range;
                const int px = i + dx * range;

                if (px < 0 || px >= N || py < 0 || py >= N)
                {
                    continue;
                }

                board[cur + 1][py][px] = true;
            }
        }
        
        sum += Solve(cur + 1, count + 1);
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    cout << Solve(0, 0) << endl;

    return 0;
}