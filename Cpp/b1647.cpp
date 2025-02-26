#include <iostream>
#include <array>
#include <vector>
#include <queue>

using namespace std;

int N, M;

constexpr int Infinite = 0xFFFFFFFF;
array<vector<pair<int, int>>, 100001> Paths;
array<int, 100001> Costs;
array<int, 100001> Parents;

int Find(const int node)
{
    if (Parents[node] == node)
    {
        return node;
    }

    return Parents[node] = Find(Parents[node]);
}

bool Union(const int nodeA, const int nodeB)
{
    const auto rootA = Find(nodeA);
    const auto rootB = Find(nodeB);
    if (rootA != rootB)
    {
        Parents[rootB] = rootA;
        return true;
    }

    return false;
}

struct SearchData
{
    int Src;
    int Dst;
    int Cost;

    explicit SearchData(const int src, const int dst, const int cost)
    : Src{src},
    Dst{dst},
    Cost{cost}
    {}

    bool operator>(const SearchData& rhs) const
    {
        return Cost > rhs.Cost;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    priority_queue<SearchData, vector<SearchData>, greater<SearchData>> priorityQueue;

    for (int i=0; i<M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Paths[a].emplace_back(b, c);
        Paths[b].emplace_back(a, c);
        Parents[a] = a;
        Parents[b] = b;

        priorityQueue.emplace(a, b, c);
    }

    int totalCost = 0;
    int mostExpensive = 0;
    while (!priorityQueue.empty())
    {
        const auto currentData = priorityQueue.top();
        priorityQueue.pop();

        if (!Union(currentData.Src, currentData.Dst))
        {
            continue;
        }

        totalCost += currentData.Cost;
        mostExpensive = max(mostExpensive, currentData.Cost);
    }

    cout << totalCost - mostExpensive << endl;

    return 0;
}