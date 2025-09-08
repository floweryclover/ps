#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int N, K;
        cin >> N >> K;

        bool visited[1001];
        int D[1001];
        int enterCounts[1001];
        int times[1001];
        vector<int> E[1001];

        for (int n = 1; n <= N; ++n)
        {
            cin >> D[n];
            visited[n] = false;
            enterCounts[n] = 0;
            times[n] = 0;
        }

        for (int k = 1; k <= K; ++k)
        {
            int src, dst;
            cin >> src >> dst;
            E[src].push_back(dst);
            enterCounts[dst] += 1;
        }

        int W;
        cin >> W;

        vector<int> Q;
        for (int n = 1; n <= N; ++n)
        {
            if (enterCounts[n] == 0)
            {
                Q.push_back(n);
            }
        }

        while (!Q.empty())
        {
            const auto cur = Q.back();
            Q.pop_back();
            if (visited[cur])
            {
                continue;
            }
            visited[cur] = true;

            if (cur == W)
            {
                cout << times[cur] + D[cur] << "\n";
                break;
            }

            for (const int dst : E[cur])
            {
                times[dst] = max(times[dst], times[cur] + D[cur]);
                enterCounts[dst] -= 1;
                if (enterCounts[dst] == 0)
                {
                    Q.emplace_back(dst);
                }
            }
        }
    }
    return 0;
}