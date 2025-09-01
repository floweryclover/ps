#include <iostream>
#include <array>
#include <limits>

using namespace std;

array<int, 100000> nums;
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }

    int minimum = numeric_limits<int>::max();
    pair<int, int> answer;

    int left = 0;
    int right = N-1;
    while (left < right)
    {
        const int sum = nums[left] + nums[right];
        const int absSum = abs(sum);

        if (absSum < minimum)
        {
            minimum = absSum;
            answer = { nums[left], nums[right] };
        }

        if (sum < 0)
        {
            left += 1;
        }
        else
        {
            right -=1 ;
        }
    }

    cout << answer.first << " " << answer.second << endl;

    return 0;
}