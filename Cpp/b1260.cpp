#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class DFS
{
private:
    stack<int> mStack;
public:
    bool IsEmpty() const
    {
        return mStack.empty();
    }
    int Pop()
    {
        int top = mStack.top();
        mStack.pop();
        return top;
    }

    void Push(int value)
    {
        mStack.push(value);
    }

    static vector<int>::const_reverse_iterator GetBeginIterator(const vector<int>& edges)
    {
        return edges.crbegin();
    }

    static vector<int>::const_reverse_iterator GetEndIterator(const vector<int>& edges)
    {
        return edges.crend();
    }
};

class BFS
{
private:
    queue<int> mQueue;
public:
    bool IsEmpty() const
    {
        return mQueue.empty();
    }
    int Pop()
    {
        int top = mQueue.front();
        mQueue.pop();
        return top;
    }

    void Push(int value)
    {
        mQueue.push(value);
    }

    static vector<int>::const_iterator GetBeginIterator(const vector<int>& edges)
    {
        return edges.cbegin();
    }

    static vector<int>::const_iterator GetEndIterator(const vector<int>& edges)
    {
        return edges.cend();
    }
};

template<typename T>
void Search(const array<vector<int>, 1001>& edges, int src)
{
    array<bool, 1001> visited;
    for (int i=0; i<1001; i++)
        visited[i] = false;
    
    T search;
    search.Push(src);
    while (!search.IsEmpty())
    {
        int current = search.Pop();

        if (visited[current])
            continue;
        visited[current] = true;
        cout << current << " ";

        for (auto iter = T::GetBeginIterator(edges[current]); iter != T::GetEndIterator(edges[current]); iter++)
        {
            if (!visited[*iter])
                search.Push(*iter);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, v;
    cin >> n >> m >> v;

    array<vector<int>, 1001> edges;
    for (int i=0; i<m; i++)
    {
        int src, dst;
        cin >> src >> dst;

        edges[src].push_back(dst);
        edges[dst].push_back(src);
    }
    for (int i=1; i<=n; i++)
        sort(edges[i].begin(), edges[i].end());

    Search<DFS>(edges, v);
    cout << "\n";
    Search<BFS>(edges, v);

    return 0;
}