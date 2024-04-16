#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

int n, m, k;
array<vector<pair<int, int>>, 10001> road;
bool visited[10001][22];

struct PqInfo
{
    int city;
    unsigned long long cost; // 다익스트라 알고리즘용
    int paveCount;

    bool operator<(const PqInfo& rhs) const 
    {
        return this->cost > rhs.cost;
    }
};

unsigned long long Solve()
{
    priority_queue<PqInfo> priorityQueue;
    priorityQueue.emplace(PqInfo { 1, 0, 0 });

    unsigned long long minimum = ULONG_LONG_MAX;
    while (!priorityQueue.empty())
    {
        auto top = priorityQueue.top();
        priorityQueue.pop();

        if (visited[top.city][top.paveCount])
            continue;
        if (top.city == n)
        {
            minimum = min(minimum, top.cost);
        }
        visited[top.city][top.paveCount] = true;

        for (auto iter = road[top.city].cbegin(); iter != road[top.city].cend(); iter++)
        {
            auto dest = iter->first;
            auto time = iter->second;

            priorityQueue.emplace(PqInfo { dest, top.cost + time, top.paveCount });
            if (top.paveCount < k)
                priorityQueue.emplace(PqInfo { dest, top.cost, top.paveCount+1 });
        }
    }
    return minimum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i=0; i<m; i++)
    {
        int a, b, time;
        cin >> a >> b >> time;
        road[a].emplace_back(b, time);
        road[b].emplace_back(a, time);
    }

    memset(visited, 0, 10001*22);

    cout << Solve() << endl;

    return 0;
}