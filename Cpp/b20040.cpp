#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int roots[500000];

int Find(const int a)
{
    if (a == roots[a])
    {
        return a;
    }
    return roots[a] = Find(roots[a]);
}

void Union(const int a, const int b)
{
    roots[Find(b)] = roots[a];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cycle = 0;

    for (int i = 0; i < 500000; ++i)
    {
        roots[i] = i;
    }

    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;

        if (Find(a) == Find(b) && cycle == 0)
        {
            cycle = i;
        }

        Union(a, b);
    }

    cout << cycle << endl;

    return 0;
}