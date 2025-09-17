#include <iostream>

using namespace std;

int n, m, k;
long long Q[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            int skill;
            cin >> skill;
            Q[i] |= (1 << skill);
        }
    }

    int maximum = 0;
    for (long long bit = 0; bit < (1 << (2 * n + 1)); ++bit)
    {
        int keyCount = 0;
        for (int key = 1; key <= (2 * n); ++key)
        {
            if (bit & (1 << key))
            {
                ++keyCount;
            }
        }
        if (keyCount != n)
        {
            continue;
        }

        int cnt = 0;
        for (int q = 1; q <= m; ++q)
        {
            if ((Q[q] & bit) == Q[q])
            {
                ++cnt;
            }
        }
        maximum = max(maximum, cnt);
    }

    cout << maximum << endl;

    return 0;
}