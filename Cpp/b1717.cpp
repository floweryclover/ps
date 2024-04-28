#include <iostream>
#include <array>

using namespace std;

struct UnionFind
{
    int* mRoots;

    UnionFind() : mRoots(new int[1000001])
    {
        for (int i=0; i<1000001; i++)
            mRoots[i] = i;
    }
    
    ~UnionFind()
    {
        delete[] mRoots;
    }

    int Find(int node) const
    {
        while (mRoots[node] != node)
            node = mRoots[node];
        return node;
    }

    void Union(const int nodeA, const int nodeB)
    {
        int rootA = Find(nodeA);
        int rootB = Find(nodeB);

        if (rootA == rootB)
            return;

        mRoots[rootB] = rootA;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    UnionFind unionFind;
    int n, m;
    cin >> n >> m;
    string result;
    for (int i=0; i<m; i++)
    {
        int operation, a, b;
        cin >> operation >> a >> b;

        if (operation == 1)
            result.append(unionFind.Find(a) == unionFind.Find(b) ? "YES\n" : "NO\n");
        else
            unionFind.Union(a, b);
    }
    if (!result.empty())
        result.pop_back();
    cout << result  << endl;

    return 0;
}