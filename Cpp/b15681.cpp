#include <iostream>
#include <vector>

using namespace std;

int N, R, Q;
vector<vector<int>> edges;
vector<int> ans;

int Solve(int parent, int current);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> R >> Q;
    edges.resize(N+1);
    ans.resize(N+1, 0);

    for (int i = 0; i < N-1; ++i)
    {
        int U, V;
        cin >> U >> V;

        edges[U].push_back(V);
        edges[V].push_back(U);
    }

    Solve(R, R);
    for (int i = 0; i < Q; ++i)
    {
        int U;
        cin >> U;
        cout << ans[U] << "\n";
    }

    return 0;
}

int Solve(const int parent, const int current)
{
    if (ans[current] > 0)
    {
        return ans[current];
    }

    int sum = 1;
    for (const int dst : edges[current])
    {
        if (dst == parent)
        {
            continue;
        }

        sum += Solve(current, dst);
    }
    return ans[current] = sum;
}