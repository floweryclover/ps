#include <iostream>
#include <queue>

using namespace std;

int N, M; // H, W
bool cheese[100][100];
int visited[100][100]; // time
pair<int, int> melt[100][100]; // time, cnt

constexpr pair<int, int> Dir[] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> cheese[i][j];
            visited[i][j] = -1;
            melt[i][j] = { -1, 0 };
        }
    }

    vector<pair<int, int>> melting;
    melting.reserve(100 * 100);
    int time = 0;
    while (true)
    {
        queue<pair<int, int>> bfs;
        bfs.emplace(0, 0);
        while (!bfs.empty())
        {
            const auto [curY, curX] = bfs.front();
            bfs.pop();

            if (visited[curY][curX] == time)
            {
                continue;
            }
            visited[curY][curX] = time;

            for (const auto [dy, dx] : Dir)
            {
                const int ny = curY + dy;
                const int nx = curX + dx;
                if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                {
                    continue;
                }

                if (cheese[ny][nx])
                {
                    if (melt[ny][nx].first != time)
                    {
                        melt[ny][nx] = { time, 1 };
                    }
                    else
                    {
                        if (++melt[ny][nx].second >= 2)
                        {
                            melting.emplace_back(ny, nx);
                        }
                    }
                }
                else if (visited[ny][nx] != time)
                {
                    bfs.emplace(ny, nx);
                }
            }
        }

        if (melting.empty())
        {
            break;
        }
        for (const auto [y, x] : melting)
        {
            if (cheese[y][x])
            {
                cheese[y][x] = false;
            }
        }
        melting.clear();

        ++time;
    }

    cout << time;

    return 0;
}