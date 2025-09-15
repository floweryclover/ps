#include <iostream>
#include <cstring>

using namespace std;

int N, M;
char boards[11][10][10];

constexpr int INF = 11;

// -1 : Failure : 0 : None 1 : Success
int Move(const int curDepth, const int dir)
{
    int result = 0;
    auto board = boards[curDepth];

    if (dir == 0) // 상
    {
        for (int x = 0; x < M; ++x)
        {
            for (int y = 1; y < N; ++y)
            {
                if (board[y][x] != 'R' && board[y][x] != 'B')
                {
                    continue;
                }

                int cur = y;
                while (cur >= 1)
                {
                    char next = board[cur - 1][x];
                    if (next == 'R' || next == 'B' || next == '#')
                    {
                        break;
                    }
                    
                    if (next == 'O')
                    {
                        if (board[cur][x] == 'R' && result == 0)
                        {
                            result = 1;
                        }
                        else
                        {
                            result = -1;
                        }
                        board[cur][x] = '.';
                        break;
                    }

                    board[cur - 1][x] = board[cur][x];
                    board[cur][x] = '.';
                    --cur;
                }
            }
        }
    }
    else if (dir == 1) // 하
    {
        for (int x = 0; x < M; ++x)
        {
            for (int y = N - 2; y >= 0; --y)
            {
                if (board[y][x] != 'R' && board[y][x] != 'B')
                {
                    continue;
                }

                int cur = y;
                while (cur < N - 1)
                {
                    char next = board[cur + 1][x];
                    if (next == 'R' || next == 'B' || next == '#')
                    {
                        break;
                    }
                    
                    if (next == 'O')
                    {
                        if (board[cur][x] == 'R' && result == 0)
                        {
                            result = 1;
                        }
                        else
                        {
                            result = -1;
                        }
                        board[cur][x] = '.';
                        break;
                    }

                    board[cur + 1][x] = board[cur][x];
                    board[cur][x] = '.';
                    ++cur;
                }
            }
        }
    }
    else if (dir == 2) // 좌
    {
        for (int y = 0; y < N; ++y)
        {
            for (int x = 1; x < M; ++x)
            {
                if (board[y][x] != 'R' && board[y][x] != 'B')
                {
                    continue;
                }

                int cur = x;
                while (cur >= 1)
                {
                    char next = board[y][cur - 1];
                    if (next == 'R' || next == 'B' || next == '#')
                    {
                        break;
                    }
                    
                    if (next == 'O')
                    {
                        if (board[y][cur] == 'R' && result == 0)
                        {
                            result = 1;
                        }
                        else
                        {
                            result = -1;
                        }
                        board[y][cur] = '.';
                        break;
                    }

                    board[y][cur - 1] = board[y][cur];
                    board[y][cur] = '.';
                    --cur;
                }
            }
        }
    }
    else // 우
    {
        for (int y = 0; y < N; ++y)
        {
            for (int x = M - 2; x >= 0; --x)
            {
                if (board[y][x] != 'R' && board[y][x] != 'B')
                {
                    continue;
                }

                int cur = x;
                while (cur < M - 1)
                {
                    char next = board[y][cur + 1];
                    if (next == 'R' || next == 'B' || next == '#')
                    {
                        break;
                    }

                    if (next == 'O')
                    {
                        if (board[y][cur] == 'R' && result == 0)
                        {
                            result = 1;
                        }
                        else
                        {
                            result = -1;
                        }
                        board[y][cur] = '.';
                        break;
                    }

                    board[y][cur + 1] = board[y][cur];
                    board[y][cur] = '.';
                    ++cur;
                }
            }
        }
    }

    return result;
}

int Solve(const int curDepth)
{
    if (curDepth == 10)
    {
        return INF;
    }

    int minimum = INF;
    for (int dir = 0; dir < 4; ++dir)
    {
        memcpy(boards[curDepth + 1], boards[curDepth], sizeof(boards[curDepth]));
        if (const int move = Move(curDepth + 1, dir);
            move != 0)
        {
            minimum = min(minimum, move == 1 ? curDepth + 1 : INF);
        }
        else
        {
            minimum = min(minimum, Solve(curDepth + 1));
        }
    }

    return minimum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int y = 0; y < N; ++y)
    {
        string input;
        cin >> input;
        for (int x = 0; x < M; ++x)
        {
            boards[0][y][x] = input[x];
        }
    }

    const int result = Solve(0);
    cout << (result != INF ? result : -1) << endl;

    return 0;
}