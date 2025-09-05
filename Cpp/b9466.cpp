#include <iostream>
#include <cstring>

using namespace std;

int A[100001];
int visited[100001];
int answer;

int Dfs(const int current)
{
    if (visited[current] == -1)
    {
        return 0;
    }
    if (visited[current] == 1)
    {
        return current;
    }
    visited[current] = 1;

    const int conjunction = Dfs(A[current]);
    if (conjunction == 0)
    {
        ++answer;
    }
    visited[current] = -1;
    if (conjunction == current)
    {
        return 0;
    }
    return conjunction;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int n;
        cin >> n;

        for (int i = 1; i <= n; ++i)
        {
            cin >> A[i];
        }
        memset(visited, 0, sizeof(visited));
        
        answer = 0;
        for (int i = 1; i <= n; ++i)
        {
            Dfs(i);
        }

        cout << answer << "\n";
    }

    return 0;
}