#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, S;
int W[13];
bool possible[2'600'001];

void Check(const int i, const int sum)
{
    if (i == k)
    {
        if (sum > 0 && sum <= S)
        {
            possible[sum] = true;
        }
        return;
    }

    Check(i + 1, sum + W[i]);
    Check(i + 1, sum - W[i]);
    Check(i + 1, sum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int input;
        cin >> input;
        S += input;
        W[i] = input;
    }

    Check(0, 0);

    int cnt = 0;
    for (int i = 1; i <= S; ++i)
    {
        if (!possible[i])
        {
            ++cnt;
        }
    }
    cout << cnt << endl;

    return 0;
}