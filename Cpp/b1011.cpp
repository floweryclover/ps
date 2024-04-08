#include <iostream>
#include <cmath>

using namespace std;

// distance : case : minimumWarpCount
//
// 0 : 0 : 1 rangeBegin
// 1 : 1 : 1 rangeEnd
// 2 : 11 : 2 ++ rangeBegin
// 3 : 111 : 3 ++ (rangeBegin + rangeEnd) / 2
// 4 : 121 : 3 rangeEnd
// 5 : 1211 : 4 ++ rangeBegin
// 6 : 1221 : 4
// 7 : 12211 : 5 ++ (rangeBegin + rangeEnd) / 2
// 8 : 12221 : 5
// 9 : 12321 : 5 rangeEnd
// 10 : 123211 : 6 ++ rangeBegin
// 11 : 123221 : 6
// 12 : 123321 : 6
// 13 : 1233211 : 7 ++ (rangeBegin + rangeEnd) / 2
// 14 : 1233221 : 7
// 15 : 1233321 : 7
// 16 : 1234321 : 7 rangeEnd
// 17 : 12343211 : 8 ++

unsigned int GetMinimumWarpCount(unsigned int distance)
{
    if (distance == 0 || distance == 1)
        return 1;
    
    int sqrtInteger = sqrt(distance);
    int rangeBegin, rangeMiddle, rangeEnd;

    if (sqrtInteger * sqrtInteger == distance)
        sqrtInteger -= 1;

    rangeBegin = sqrtInteger * sqrtInteger + 1;
    rangeEnd = (sqrtInteger+1) * (sqrtInteger+1);
    rangeMiddle = (rangeBegin+rangeEnd)/2;

    int returnValue = sqrtInteger * 2;
    if (distance >= rangeMiddle)
        returnValue++;
    
    return returnValue;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i=0; i<t; i++)
    {
        unsigned int x, y;
        cin >> x >> y;

        cout << GetMinimumWarpCount(y - x) << endl;
    }

    return 0;
}