#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> E[32001];
int enterCounts[32001];
bool visited[32001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(enterCounts, 0, sizeof(enterCounts));

    cin >> N >> M;
    for (int i = 1; i <= M; ++i)
    {
        int src, dst;
        cin >> src >> dst;

        E[src].push_back(dst);
        enterCounts[dst] += 1;
    }

    vector<int> Q;
    Q.reserve(100000);
    for (int i = 1; i <= N; ++i)
    {
        if (enterCounts[i] == 0)
        {
            Q.push_back(i);
        }
    }

    while (!Q.empty())
    {
        const int cur = Q.back();
        Q.pop_back();
        if (visited[cur])
        {
            continue;
        }
        cout << cur << " ";

        for (const int dst : E[cur])
        {
            enterCounts[dst] -= 1;
            if (enterCounts[dst] == 0)
            {
                Q.push_back(dst);
            }
        }
    }

    return 0;
}