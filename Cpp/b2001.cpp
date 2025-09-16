#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m, K;

int B[101][101]; // 0: 다리 없음
bool V[101];
int pathCache[15][101][101]; // 보석개수, from, to. -1 길 없음 0 탐색 안됨 1 길 있음
int dp[(1 << 15)][15];

bool HasPath(const int v, const int from, const int to)
{
    if (pathCache[v][from][to] != 0)
    {
        return pathCache[v][from][to] == 1;
    }

    queue<int> bfs;
    bfs.push(from);

    bool visited[101];
    memset(visited, 0, sizeof(visited));

    while (!bfs.empty())
    {
        const int cur = bfs.front();
        bfs.pop();

        if (visited[cur])
        {
            continue;
        }
        visited[cur] = true;
        if (cur == to)
        {
            for (int weight = 0; weight <= v; ++weight)
            {
                pathCache[weight][from][to] = pathCache[weight][to][from] = 1;
            }
            break;
        }

        for (int next = 1; next <= n; ++next)
        {
            if (B[cur][next] == 0 || B[cur][next] < v || visited[next])
            {
                continue;
            }

            bfs.push(next);
        }
    }

    return pathCache[v][from][to] == 1;
}

int GetCount(const int bit)
{
    int count = 0;
    for (int i = 1; i <= K; ++i)
    {
        if (bit & (1 << i))
        {
            ++count;
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> K;
    for (int i = 1; i <= K; ++i)
    {
        int input;
        cin >> input;

        V[input] = true;
    }

    for (int i = 1; i <= m; ++i)
    {
        int src, dst, limit;
        cin >> src >> dst >> limit;
        B[src][dst] = limit;
        B[dst][src] = limit;
    }

    memset(dp, -1, sizeof(dp));
    memset(pathCache, 0, sizeof(pathCache));
    dp[1 << 1][1] = 0;
    for (int v = 2; v <= K; ++v)
    {
        for (int bit = (1 << 1); bit < (1 << (K + 1)); ++bit)
        {
            if (GetCount(bit) != v)
            {
                continue;
            }

            for (int cur = 2; cur <= K; ++cur)
            {
                if (!(bit & (1 << cur)))
                {
                    continue;
                }

                for (int prv = 1; prv <= K; ++prv)
                {
                    if (!(bit & (1 << prv)) || cur == prv)
                    {
                        continue;
                    }

                    const int prvCount = dp[bit & ~(1 << cur)][prv];
                    if (prvCount == -1 || !HasPath(prvCount, prv, cur))
                    {
                        continue;
                    }
                    dp[bit][cur] = max(dp[bit][cur], prvCount + 1);
                }
            }
        }
    }

    int maximum = 0;
    for (int bit = (1 << 1); bit < (1 << (K + 1)); ++bit)
    {
        for (int cur = 2; cur <= K; ++cur)
        {
            if (!(bit & (1 << cur)))
            {
                continue;
            }

            const int prvCount = dp[bit][cur];
            if (prvCount == -1 || !HasPath(prvCount, cur, 1))
            {
                continue;
            }

            maximum = max(maximum, dp[bit][cur]);
        }
    }

    cout << maximum + V[1] << endl;

    return 0;
}