#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
bool know[101][101];
bool visited[101];
int group[101]; // 0: 그룹 없음
int groupMinCost[101];
int groupLeader[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= M; ++i)
    {
        int src, dst;
        cin >> src >> dst;
        know[src][dst] = true;
        know[dst][src] = true;
    }

    for (int i = 0; i <= 100; ++i)
    {
        groupMinCost[i] = 101;
    }

    int K = 0;
    for (int p = 1; p <= N; ++p)
    {
        if (group[p] == 0)
        {
            K += 1;
            group[p] = K;
        }
        
        memset(visited, 0, sizeof(visited));
        queue<pair<int, int>> bfs;
        bfs.emplace(p, -1);
        int maxCost = 0;
        while (!bfs.empty())
        {
            const auto [cur, cost] = bfs.front();
            bfs.pop();

            if (visited[cur])
            {
                continue;
            }
            visited[cur] = true;
            if (group[cur] == 0)
            {
                group[cur] = group[p];
            }
            maxCost = max(maxCost, cost);

            for (int other = 1; other <= N; ++other)
            {
                if (know[cur][other] && !visited[other])
                {
                    bfs.emplace(other, cost + 1);
                }
            }
        }

        if (maxCost < groupMinCost[group[p]])
        {
            groupMinCost[group[p]] = maxCost;
            groupLeader[group[p]] = p;
        }
    }

    cout << K << endl;

    vector<int> leaders;
    for (int g = 1; g <= K; ++g)
    {
        leaders.push_back(groupLeader[g]);
    }
    sort(leaders.begin(), leaders.end());

    for (const int leader : leaders)
    {
        cout << leader << "\n";
    }

    return 0;
}