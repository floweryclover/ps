#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
vector<int> E[100001];
bool visited[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int src, dst;
        cin >> src >> dst;
        E[src].push_back(dst);
        E[dst].push_back(src);
    }

    queue<vector<int>> q;
    q.emplace().push_back(1);
    visited[1] = true;
    bool failed = false;
    for (int i = 0; i < N; ++i)
    {
        int visit;
        cin >> visit;
        
        int found = false;
        for (auto iter = q.front().begin(); iter != q.front().end(); ++iter)
        {
            if (*iter == visit)
            {
                found = true;
                vector<int> next;
                for (const int dst : E[visit])
                {
                    if (!visited[dst])
                    {
                        visited[dst] = true;
                        next.push_back(dst);
                    }
                }

                if (!next.empty())
                {
                    q.emplace(std::move(next));
                }

                q.front().erase(iter);
                if (q.front().empty())
                {
                    q.pop();
                }
                break;
            }
        }

        if (!found)
        {
            failed = true;
        }
    }

    cout << (failed ? 0 : 1);
    return 0;
}