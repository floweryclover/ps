#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;

int D[101][101];

constexpr int INF = 100'000 * 101 + 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for (int i = 0; i <= 100; ++i)
    {
        for (int j = 0; j <= 100; ++j)
        {
            D[i][j] = INF;
        }
    }

    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int src, dst, cost;
        cin >> src >> dst >> cost;

        D[src][dst] = min(D[src][dst], cost);
    }

    for (int mid = 1; mid <= n; ++mid)
    {
        for (int start = 1; start <= n; ++start)
        {
            for (int end = 1; end <= n; ++end)
            {
                D[start][end] = min(D[start][end], D[start][mid] + D[mid][end]);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << (D[i][j] == INF || i == j ? 0 : D[i][j]) << " ";
        }
        cout << "\n";
    }

    return 0;
}