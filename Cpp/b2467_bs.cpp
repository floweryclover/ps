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

    for (int i = 0; i < N-1; ++i)
    {
        int left = i + 1;
        int right = N-1;
        int mid;
        
        while (left <= right)
        {
            mid = (left + right) / 2;

            const int sum = nums[i] + nums[mid];
            const int absSum = abs(sum);
    
            if (absSum < minimum)
            {
                minimum = absSum;
                answer = { nums[i], nums[mid] };
            }
            
            if (nums[mid] == -nums[i])
            {
                break;
            }
            else if (nums[mid] > -nums[i])
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }

    }

    cout << answer.first << " " << answer.second << endl;

    return 0;
}