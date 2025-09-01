#include <iostream>
#include <array>
#include <cstring>

using namespace std;

string strA, strB;  //   A
                    // B
array<array<int, 1001>, 1001> DP;
array<array<string, 1001>, 2> window;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> strA;
    cin >> strB;

    for (int idxB = 0; idxB <= strB.length(); ++idxB)
    {
        DP[idxB][0] = 0;
    }
    for (int idxA = 0; idxA <= strA.length(); ++idxA)
    {
        DP[0][idxA] = 0;
    }

    int prevWindowRow = 0;
    int curWindowRow = 1;
    for (int lenB = 1; lenB <= strB.length(); ++lenB)
    {
        for (int lenA = 1; lenA <= strA.length(); ++lenA)
        {
            if (const bool isCommon = strA[lenA-1] == strB[lenB-1])
            {
                DP[lenB][lenA] = DP[lenB-1][lenA-1] + 1;
                window[curWindowRow][lenA] = window[prevWindowRow][lenA-1];
                window[curWindowRow][lenA] += strA[lenA-1];
            }
            else
            {
                const bool fromLeft = DP[lenB][lenA-1] >= DP[lenB-1][lenA];
                DP[lenB][lenA] = DP[lenB - (fromLeft ? 0 : 1)][lenA - (fromLeft ? 1 : 0)];
                window[curWindowRow][lenA] = window[fromLeft ? curWindowRow : prevWindowRow][lenA - (fromLeft ? 1 : 0)];   
            }
        }
        curWindowRow = 1 - curWindowRow;
        prevWindowRow = 1 - prevWindowRow;
    }

    const int lcsLength = DP[strB.length()][strA.length()];
    cout << lcsLength << endl;
    if (lcsLength > 0)
    {
        cout << window[prevWindowRow][strA.length()] << endl;
    }

    return 0;
}