#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Sequence(vector<int>& result, const vector<int>& nums, unsigned short idx, int current, unsigned short remainingAdd, unsigned short remainingMinus, unsigned short remainingMultiply, unsigned short remainingDivide)
{
    if (idx == nums.size())
    {
        result.push_back(current);
        return;
    }

    if (remainingAdd > 0)        Sequence(result, nums, idx+1, current + nums[idx], remainingAdd-1, remainingMinus, remainingMultiply, remainingDivide);
    if (remainingMinus > 0)      Sequence(result, nums, idx+1, current - nums[idx], remainingAdd, remainingMinus-1, remainingMultiply, remainingDivide);
    if (remainingMultiply > 0)   Sequence(result, nums, idx+1, current * nums[idx], remainingAdd, remainingMinus, remainingMultiply-1, remainingDivide);
    if (remainingDivide > 0)     Sequence(result, nums, idx+1, current / nums[idx], remainingAdd, remainingMinus, remainingMultiply, remainingDivide-1);
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i<n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    unsigned short addCount, minusCount, multiplyCount, divideCount;
    cin >> addCount;
    cin >> minusCount;
    cin >> multiplyCount;
    cin >> divideCount;

    vector<int> result;
    Sequence(result, nums, 1, nums[0], addCount, minusCount, multiplyCount, divideCount);
    sort(result.begin(), result.end());

    cout << *(result.end()-1) << endl;
    cout << *(result.begin()) << endl;
}