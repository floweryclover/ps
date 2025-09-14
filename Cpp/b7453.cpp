#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int num[5][4001];
vector<int> AB;
vector<int> CD;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 4; ++j)
        {
            cin >> num[j][i];
        }
    }
    
    AB.reserve(4000 * 4000);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            AB.push_back(num[1][i] + num[2][j]);
        }
    }
    sort(AB.begin(), AB.end());

    CD.reserve(4000 * 4000);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            CD.push_back(-num[3][i] - num[4][j]);
        }
    }
    sort(CD.begin(), CD.end());


    unsigned long long ans = 0;
    int ab = 0;
    int cd = 0;
    while (ab < AB.size() && cd < CD.size())
    {
        const int nAB = AB[ab];
        const int nCD = CD[cd];

        if (nAB == nCD)
        {
            unsigned long long cntAB = 0;
            while (AB[ab] == nAB && ab < AB.size())
            {
                ++ab;
                ++cntAB;
            }

            unsigned long long cntCD = 0;
            while (CD[cd] == nCD && cd < CD.size())
            {
                ++cd;
                ++cntCD;
            }

            ans += cntAB * cntCD;
        }
        else if (nAB > nCD)
        {
            ++cd;
        }
        else
        {
            ++ab;
        }
    }

    cout << ans << endl;

    return 0;
}