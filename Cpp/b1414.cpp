#include <iostream>
#include <string>
#include <queue>
#include <array>

using namespace std;

struct Edge
{
    int src;
    int dst;
    int length;

    bool operator<(const Edge& rhs) const
    {
        return length > rhs.length;
    }
};

class UnionFind
{
private:
    static constexpr int ROOT_PARENT = 50;
    array<int, 51> mParents;

public:
    UnionFind()
    {
        for (int i=0; i<51; i++)
            mParents[i] = ROOT_PARENT;
    }

    int GetParent(int node)
    {
        return mParents[node];
    }

    int GetRoot(int node)
    {
        int root = node;
        while (GetParent(root) != ROOT_PARENT)
        {
            root = GetParent(root);
        }
            
        return root;
    }

    void Union(int nodeA, int nodeB)
    {
        int rootA = GetRoot(nodeA);
        int rootB = GetRoot(nodeB);

        if (rootA == rootB)
            return;

        mParents[rootB] = rootA;
    }

    bool IsAllUnion(int nodes)
    {
        int rootNodeCount = 0;
        for (int i=0; i<nodes; i++)
        {
            if (mParents[i] == ROOT_PARENT)
                rootNodeCount++;
        }
        return rootNodeCount == 1;
    }
};

int n;
priority_queue<Edge> minHeap;

int MST()
{
    UnionFind unionFind;
    int totalLength = 0;
    while (!minHeap.empty())
    {
        auto edge = minHeap.top();
        minHeap.pop();

        if (unionFind.GetRoot(edge.src) == unionFind.GetRoot(edge.dst))
            continue;
        
        unionFind.Union(edge.src, edge.dst);
        totalLength += edge.length;
    }

    if (unionFind.IsAllUnion(n))
        return totalLength;
    else
        return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int totalLength = 0;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        string input;
        cin >> input;
        for (int j=0; j<n; j++)
        {
            char ch = input[j];

            if (ch == '0')
                continue;

            int length;
            if (ch >= 'a')
                length = ch - 'a' + 1;
            else
                length = ch - 'A' + 27;
            totalLength += length;
            
            if (i==j)
                continue;
            
            minHeap.emplace(Edge { i, j, length });
        }
    }

    int mst = MST();
    cout << (mst == -1 ? -1 : totalLength - mst) << endl;

    return 0;
}