#include <iostream>
#include <array>
#include <algorithm>
#include <cstdint>

using namespace std;

int Solve(const int leftInclusive, const int rightExclusive);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    array<int, 50> nums;

    cin >> n;
    for (int i=0; i<n; ++i)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.begin()+n);

    int largest = 0;

    for (int left = 0; left <n; ++left)
    {
        for (int right = n; right>left; --right)
        {
            if (right-left < 3)
            {
                largest = max(largest, right-left);
            }
            else if (nums[left]+nums[left+1] > nums[right-1])
            {
                largest = max(largest, right-left);
            }
        }
    }

    cout << largest << endl;

    return 0;
}