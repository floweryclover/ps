#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
int boardStack[6][20][20];

void Move(const int dir, const int depth)
{
    if (dir == 0) // 위
    {
        for (int x = 0; x < N; ++x)
        {
            queue<pair<int, bool>> q;
            for (int y = 0; y < N; ++y)
            {
                if (boardStack[depth][y][x] == 0)
                {
                    continue;
                }

                if (!q.empty() && q.back().first == boardStack[depth][y][x] && !q.back().second)
                {
                    q.back().first *= 2;
                    q.back().second = true;
                }
                else
                {
                    q.emplace(boardStack[depth][y][x], false);
                }
                boardStack[depth][y][x] = 0;
            }

            int idx = 0;
            while (!q.empty())
            {
                const int block = q.front().first;
                q.pop();
                boardStack[depth][idx][x] = block;
                ++idx;
            }
        }
    }
    else if (dir == 1) // 아래
    {
        for (int x = 0; x < N; ++x)
        {
            queue<pair<int, bool>> q;
            for (int y = N - 1; y >= 0; --y)
            {
                if (boardStack[depth][y][x] == 0)
                {
                    continue;
                }
            
                if (!q.empty() && q.back().first == boardStack[depth][y][x] && !q.back().second)
                {
                    q.back().first *= 2;
                    q.back().second = true;
                }
                else
                {
                    q.emplace(boardStack[depth][y][x], false);
                }
                boardStack[depth][y][x] = 0;
            }

            int idx = N - 1;
            while (!q.empty())
            {
                const int block = q.front().first;
                q.pop();
                boardStack[depth][idx][x] = block;
                --idx;
            }
        }
    }
    else if (dir == 2) // 왼
    {
        for (int y = 0; y < N; ++y)
        {
            queue<pair<int, bool>> q;
            for (int x = 0; x < N; ++x)
            {
                if (boardStack[depth][y][x] == 0)
                {
                    continue;
                }
            
                if (!q.empty() && q.back().first == boardStack[depth][y][x] && !q.back().second)
                {
                    q.back().first *= 2;
                    q.back().second = true;
                }
                else
                {
                    q.emplace(boardStack[depth][y][x], false);
                }
                boardStack[depth][y][x] = 0;
            }

            int idx = 0;
            while (!q.empty())
            {
                const int block = q.front().first;
                q.pop();
                boardStack[depth][y][idx] = block;
                ++idx;
            }
        }
    }
    else // 오
    {
        queue<pair<int, bool>> q;
        for (int y = 0; y < N; ++y)
        {
            for (int x = N - 1; x >= 0; --x)
            {
                if (boardStack[depth][y][x] == 0)
                {
                    continue;
                }

                if (!q.empty() && q.back().first == boardStack[depth][y][x] && !q.back().second)
                {
                    q.back().first *= 2;
                    q.back().second = true;
                }
                else
                {
                    q.emplace(boardStack[depth][y][x], false);
                }
                boardStack[depth][y][x] = 0;
            }

            int idx = N - 1;
            while (!q.empty())
            {
                const int block = q.front().first;
                q.pop();
                boardStack[depth][y][idx] = block;
                --idx;
            }
        }
    }
}

int Solve(const int depth)
{
    if (depth == 5)
    {
        int maxBlock = 0;
        for (int y = 0; y < N; ++y)
        {
            for (int x = 0; x < N; ++x)
            {
                maxBlock = max(maxBlock, boardStack[depth][y][x]);
            }
        }
        return maxBlock;
    }

    int maximum = 0;
    for (int dir = 0; dir < 4; ++dir)
    {
        memcpy(boardStack[depth + 1], boardStack[depth], sizeof(boardStack[depth]));
        Move(dir, depth + 1);
        maximum = max(maximum, Solve(depth + 1));
    }

    return maximum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> boardStack[0][i][j];
        }
    }

    cout << Solve(0) << endl;

    return 0;
}