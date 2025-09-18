#include <iostream>

using namespace std;

int N, M;
int t[501][501];

constexpr int Inf = 1'000'000 * 501;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> t[i][j];
            if (t[i][j] == 0)
            {
                t[i][j] = Inf;
            }
        }
    }

    for (int m = 1; m <= N; ++m)
    {
        for (int s = 1; s <= N; ++s)
        {
            for (int e = 1; e <= N; ++e)
            {
                t[s][e] = min(t[s][e], t[s][m] + t[m][e]);
            }
        }
    }

    for (int i = 0; i < M; ++i)
    {
        int src, dst, maximum;
        cin >> src >> dst >> maximum;

        if (t[src][dst] <= maximum)
        {
            cout << "Enjoy other party\n";
        }
        else
        {
            cout << "Stay here\n";
        }
    }

    return 0;
}