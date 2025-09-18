#include <iostream>
#include <queue>

using namespace std;

int N, M;

int maxRoots[1001];
int minRoots[1001];

int Find(int roots[1001], const int a)
{
    if (a == roots[a])
    {
        return a;
    }
    return roots[a] = Find(roots, roots[a]);
}

bool Union(int roots[1001], const int a, const int b)
{
    const int rootA = Find(roots, a);
    const int rootB = Find(roots, b);

    roots[rootB] = rootA;
    return rootA == rootB;
}

struct Edge
{
    explicit Edge(const int src, const int dst, const int cost)
    : Src{src}, Dst{dst}, Cost{cost} {}

    int Src;
    int Dst;
    int Cost;
};

struct Less
{
    bool operator()(const Edge& lhs, const Edge& rhs) const { return lhs.Cost < rhs.Cost; }
};

struct Greater
{
    bool operator()(const Edge& lhs, const Edge& rhs) const { return lhs.Cost > rhs.Cost; }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    priority_queue<Edge, vector<Edge>, Less> maxPq;
    priority_queue<Edge, vector<Edge>, Greater> minPq;
    
    for (int i = 0; i <= M; ++i)
    {
        int src, dst, cost;
        cin >> src >> dst >> cost;

        maxPq.emplace(src, dst, 1 - cost);
        minPq.emplace(src, dst, 1 - cost);
    }

    for (int i = 0; i <= 1000; ++i)
    {
        maxRoots[i] = minRoots[i] = i;
    }

    int maximum = 0;
    while (!maxPq.empty())
    {
        const auto [src, dst, cost] = maxPq.top();
        maxPq.pop();

        if (Union(maxRoots, src, dst))
        {
            continue;
        }

        maximum += cost;
    }

    int minimum = 0;
    while (!minPq.empty())
    {
        const auto [src, dst, cost] = minPq.top();
        minPq.pop();
        
        if (Union(minRoots, src, dst))
        {
            continue;
        }

        minimum += cost;
    }

    cout << maximum * maximum - minimum * minimum << endl;

    return 0;
}