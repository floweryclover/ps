#include <iostream>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string strA, strB, strC;
    cin >> strA >> strB >> strC;
;

    array<array<array<int, 101>, 101>, 101> lcs;

    for (int i=0; i<101; ++i)
    {
        for (int j=0; j<101; ++j)
        {
            lcs[0][i][j] = 0;
            lcs[i][0][j] = 0;
            lcs[i][j][0] = 0;
        }
    }

    for (int lenA=1; lenA <= strA.length(); ++lenA)
    {
        for (int lenB = 1; lenB <= strB.length(); ++lenB)
        {
            for (int lenC = 1; lenC <= strC.length(); ++lenC)
            {
                if (strA[lenA-1] == strB[lenB-1] &&
                    strB[lenB-1] == strC[lenC-1] &&
                    strC[lenC-1] == strA[lenA-1])
                {
                    lcs[lenA][lenB][lenC] = lcs[lenA-1][lenB-1][lenC-1] + 1;
                }
                else
                {
                    int maximum = 0;
                    maximum = max(maximum, lcs[lenA-1][lenB][lenC]);
                    maximum = max(maximum, lcs[lenA][lenB-1][lenC]);
                    maximum = max(maximum, lcs[lenA][lenB][lenC-1]);
                    lcs[lenA][lenB][lenC] = maximum;
                }
            }
        }
    }

    cout << lcs[strA.length()][strB.length()][strC.length()] << endl;

    return 0;
}