#include <iostream>
#include <cmath>

using namespace std;

using LL = long long;

pair<LL, LL> p[4]; 

int CCW(const int p0, const int p1, const int p2)
{
    const long long cross = (p[p0].first - p[p1].first) * (p[p2].second - p[p0].second) - (p[p2].first - p[p0].first) * (p[p0].second - p[p1].second);

    if (cross > 0)
    {
        return 1;
    }
    if (cross < 0)
    {
        return -1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 4; ++i)
    {
        cin >> p[i].first >> p[i].second;
    }
    
    const int a = CCW(0, 1, 2) * CCW(0, 1, 3);
    const int b = CCW(2, 3, 0) * CCW(2, 3, 1);

    if (a == 0 && b == 0)
    {
        if (p[0] > p[1])
        {
            swap(p[0], p[1]);
        }
        if (p[2] > p[3])
        {
            swap(p[2], p[3]);
        }
        if (p[0] > p[2])
        {
            swap(p[0], p[2]);
            swap(p[1], p[3]);
        }

        cout << (p[0] <= p[3] && p[1] >= p[2]) << endl;
    }
    else
    {
        cout << (a <= 0 && b <= 0) << endl;
    }
    
    return 0;
}