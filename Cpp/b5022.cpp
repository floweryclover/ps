#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int N, M; // W, H
pair<int, int> A1, A2, B1, B2;

constexpr pair<int, int> Dir[] = {{1,0},{0,-1},{-1,0},{0,1}};
constexpr int Inf = 103 * 103;
bool visited[102][102];
pair<int, int> parent[102][102];

int Bfs(const pair<int, int> from, const pair<int, int> to, const pair<int, int> avoidA, const pair<int, int> avoidB)
{
    queue<tuple<int, int, int, int, int>> bfs;
    bfs.emplace(from.first, from.second, -1, -1, 0);
    while (!bfs.empty())
    {
        const auto [curX, curY, prvX, prvY, cost] = bfs.front();
        bfs.pop();

        if (visited[curX][curY])
        {
            continue;
        }
        visited[curX][curY] = true;
        parent[curX][curY] = { prvX, prvY };
        if (curX == to.first && curY == to.second)
        {
            return cost;
        }

        for (const auto [dx, dy] : Dir)
        {
            const int nx = curX + dx;
            const int ny = curY + dy;
            if (nx == avoidA.first && ny == avoidA.second ||
                nx == avoidB.first && ny == avoidB.second ||
                nx < 0 || nx > N || ny < 0 || ny > M || visited[nx][ny])
            {
                continue;
            }

            bfs.emplace(nx, ny, curX, curY, cost + 1);
        }
    }

    return Inf;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> A1.first >> A1.second >> A2.first >> A2.second >> B1.first >> B1.second >> B2.first >> B2.second;
    int minimum = Inf;

    // A -> B
    {
        for (int x = 0; x <= N; ++x)
        {
            for (int y = 0; y <= M; ++y)
            {
                parent[x][y] = { -1, -1 };
            }
        }
        const int aLen = Bfs(A1, A2, B1, B2);
        memset(visited, 0, sizeof(visited));
        auto cur = parent[A2.first][A2.second];
        while (cur != pair<int, int>{ -1, -1 })
        {
            visited[cur.first][cur.second] = true;
            cur = parent[cur.first][cur.second];
        }
        const int bLen = Bfs(B1, B2, A1, A2);
        minimum = min(minimum, aLen + bLen);
    }
    
    // B -> A
    {
        for (int x = 0; x <= N; ++x)
        {
            for (int y = 0; y <= M; ++y)
            {
                parent[x][y] = { -1, -1 };
            }
        }
        memset(visited, 0, sizeof(visited));
        const int bLen = Bfs(B1, B2, A1, A2);
        memset(visited, 0, sizeof(visited));
        auto cur = parent[B2.first][B2.second];
        while (cur != pair<int, int>{ -1, -1 })
        {
            visited[cur.first][cur.second] = true;
            cur = parent[cur.first][cur.second];
        }
        const int aLen = Bfs(A1, A2, B1, B2);
        minimum = min(minimum, aLen + bLen);

    }

    if (minimum != Inf)
    {
        cout << minimum;
    }
    else
    {
        cout << "IMPOSSIBLE";
    }

    return 0;
}