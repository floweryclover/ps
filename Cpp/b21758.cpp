#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    arr.reserve(N);

    int totalHoney = 0;
    int minimum = 99999;
    for (int i=0; i<N; ++i)
    {
        int input;
        cin >> input;
        arr.push_back(input);
        totalHoney += input;
        minimum = min(input, minimum);
    }

    const int maximumBetweenBees = []
    {
        int maximum = 0;
        for (int i=1; i<N-1; ++i)
        {
            maximum = max(arr[i], maximum);
        }
        return maximum;
    }();

    // 벌통이 벌 사이에 있음
    int answer = totalHoney - arr[0] - arr[N-1] + maximumBetweenBees;

    // 왼쪽 끝
    const int wastedWhenLeft = []
    {
        int minimumWasted = 99999;
        for (int pos = N-2; pos > 0; --pos)
        {
            int wasted = arr[pos];
            for (int ignoredPos = pos; ignoredPos < N; ++ignoredPos)
            {
                wasted += arr[ignoredPos]; // 안쪽 벌 버려지는 양
            }
            minimumWasted = min(minimumWasted, wasted);
        }
        return minimumWasted;
    }();
    answer = max(answer, totalHoney * 2 - arr[N-1] - wastedWhenLeft);

    // 오른쪽 끝
    const int wastedWhenRight = []
    {
        int minimumWasted = 99999;
        for (int pos = 1; pos < N-1; ++pos)
        {
            int wasted = arr[pos];
            for (int ignoredPos = 0; ignoredPos <= pos; ++ignoredPos)
            {
                wasted += arr[ignoredPos];
            }
            minimumWasted = min(minimumWasted, wasted);
        }
        return minimumWasted;
    }();
    answer = max(answer, totalHoney * 2 - arr[0] - wastedWhenRight);

    cout << answer << endl;

    return 0;
}