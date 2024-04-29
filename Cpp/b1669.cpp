#include <iostream>
#include <cmath>

using namespace std;

/*
    키 차이  :  최소 경로  :  횟수
    0          0             0
    1          1             1 ++ 
    2          1 1           2 ++   rangeBegin
    3          1 1 1         3 ++   rangeMid
    4          1 2 1         3      rangeEnd
    5          1 2 1 1       4 ++   rangeBegin
    6          1 2 2 1       4 
    7          1 2 2 1 1     5 ++   rangeMid
    8          1 2 2 2 1     5
    9          1 2 3 2 1     5      rangeEnd
    10         1 2 3 2 1 1   6 ++   rangeBegin
    11         1 2 3 2 2 1   6
    12         1 2 3 3 2 1   6
    13         1 2 3 3 2 1 1 7 ++   rangeMid
    14         1 2 3 3 2 2 1 7
    15         1 2 3 3 3 2 1 7
    16         1 2 3 4 3 2 1 7      rangeEnd
    17                         ++
*/

unsigned long long Solve(const unsigned long long difference)
{
    if (difference == 0)
        return 0;
    else if (difference == 1)
        return 1;
    double root = sqrt(difference);
    unsigned long long range;// range: rangeBegin ~ rangeBegin이 지금 몇번째인지(n.xx에서 n)
    if (static_cast<unsigned long long>(root)*static_cast<unsigned long long>(root) ==  difference)
        range = round(root-1);
    else
        range = floor(root);

    unsigned long long rangeBegin = range*range+1;
    unsigned long long rangeEnd = (range+1)*(range+1);
    unsigned long long rangeMid = (rangeBegin + rangeEnd) / 2;
    
    if (difference >= rangeMid)
        return 2*range+1;
    else
        return 2*range;
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << Solve(y-x) << endl;
    return 0;
}