#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;

vector<int> A[1001];
int enter[1001];
bool visited[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(enter, 0, sizeof(enter));
    cin >> N >> M;
    for (int i = 1; i <= M; ++i)
    {
        int count;
        cin >> count;

        int prv = -1;
        for (int j = 1; j <= count; ++j)
        {
            int input;
            cin >> input;

            if (prv != -1)
            {
                ++enter[input];
                A[prv].push_back(input);
            }

            prv = input;

        }
    }
    vector<int> search;
    search.reserve(1001);
    for (int i = 1; i <= N; ++i)
    {
        if (enter[i] == 0)
        {
            search.push_back(i);
        }
    }

    vector<int> order;
    order.reserve(1001);
    memset(visited, 0, sizeof(visited));
    while (!search.empty())
    {
        const int cur = search.back();
        search.pop_back();

        if (visited[cur])
        {
            continue;
        }
        visited[cur] = true;
        order.push_back(cur);
        
        for (const int dst : A[cur])
        {
            --enter[dst];
            if (enter[dst] == 0 && !visited[dst])
            {
                search.push_back(dst);
            }
        }
    }

    if (order.size() == N)
    {
        for (const int n : order)
        {
            cout << n << "\n";
        }
    }
    else
    {
        cout << 0 << endl;
    }

    return 0;
}