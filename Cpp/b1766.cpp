#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
vector<int> order[32001];
int enter[32001];
bool solved[32001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    memset(enter, 0, sizeof(enter));
    memset(solved, 0, sizeof(solved));

    for (int i = 1; i <= M; ++i)
    {
        int a, b;
        cin >> a >> b;

        order[a].push_back(b);
        ++enter[b];
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; ++i)
    {
        if (enter[i] == 0)
        {
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        const int cur = pq.top();
        pq.pop();
        if (solved[cur])
        {
            continue;
        }
        cout << cur << " ";
        solved[cur] = true;

        for (const int dst : order[cur])
        {
            --enter[dst];
            if (enter[dst] == 0)
            {
                pq.push(dst);
            }
        }
    }

    return 0;
}