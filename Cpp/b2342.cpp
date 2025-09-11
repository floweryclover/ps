#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int step[100001];
int dp[100001][5][5];

int GetCost(const int curLeft, const int curRight, const int prevLeft, const int prevRight)
{
    if (curLeft != prevLeft && curRight != prevRight)
    {
        return -1;
    }

    int prev, cur;
    if (curLeft != prevLeft)
    {
        cur = curLeft;
        prev = prevLeft;
    }
    else
    {
        cur = curRight;
        prev = prevRight;
    }

    if (cur == prev)
    {
        return 1;
    }
    if (cur == 0)
    {
        return -1;
    }
    if (prev == 0)
    {
        return 2;
    }
    if (abs(cur - prev) == 2)
    {
        return 4;
    }
    return 3;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count = 0;
    while (true)
    {
        cin >> step[count + 1];
        if (step[count + 1] == 0)
        {
            break;
        }

        ++count;
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i <= count; ++i)
    {
        for (int otherStep = 0; otherStep <= 4; ++otherStep)
        {
            for (int prevLeft = 0; prevLeft <= 4; ++prevLeft)
            {
                for (int prevRight = 0; prevRight <= 4; ++prevRight)
                {
                    const int prevValue = dp[i - 1][prevLeft][prevRight];
                    if (prevValue == -1)
                    {
                        continue;
                    }

                    const int leftCost = GetCost(step[i], otherStep, prevLeft, prevRight);
                    const int rightCost = GetCost(otherStep, step[i], prevLeft, prevRight);
                    if (leftCost != -1)
                    {
                        dp[i][step[i]][otherStep] = dp[i][step[i]][otherStep] == -1 ? prevValue + leftCost : min(dp[i][step[i]][otherStep], prevValue + leftCost);
                    }
                    if (rightCost != -1)
                    {
                        dp[i][otherStep][step[i]] = dp[i][otherStep][step[i]] == -1 ? prevValue + rightCost : min(dp[i][otherStep][step[i]], prevValue + rightCost);
                    }
                }
            }
        }
    }
    int minimum = 400'000;
    for (int i = 0; i <= 4; ++i)
    {
        if (dp[count][step[count]][i] != -1)
        {
            minimum = min(minimum, dp[count][step[count]][i]);
        }
        if (dp[count][i][step[count]] != -1)
        {
            minimum = min(minimum, dp[count][i][step[count]]);
        }
    }
    cout << minimum << endl;

    return 0;
}