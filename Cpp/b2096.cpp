#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    int prevLeftMin, prevLeftMax, prevMidMin, prevMidMax, prevRightMin, prevRightMax;
    int currentLeftMin, currentLeftMax, currentMidMin, currentMidMax, currentRightMin, currentRightMax;
    for (int i=0; i<n; i++)
    {
        int left, mid, right;
        cin >> left >> mid >> right;

        if (i == 0)
        {
            prevLeftMin = prevLeftMax = currentLeftMin = currentLeftMax = left;
            prevMidMin = prevMidMax = currentMidMin = currentMidMax = mid;
            prevRightMin = prevRightMax = currentRightMin = currentRightMax = right;
        }
        else
        {
            currentLeftMin = min(prevLeftMin, prevMidMin)                       + left;
            currentMidMin = min(min(prevLeftMin, prevMidMin), prevRightMin)     + mid;
            currentRightMin = min(prevMidMin, prevRightMin)                     + right;

            currentLeftMax = max(prevLeftMax, prevMidMax)                       + left;
            currentMidMax = max(max(prevLeftMax, prevMidMax), prevRightMax)     + mid;
            currentRightMax = max(prevMidMax, prevRightMax)                     + right;

            prevLeftMin = currentLeftMin;
            prevMidMin = currentMidMin;
            prevRightMin = currentRightMin;

            prevLeftMax = currentLeftMax;
            prevMidMax = currentMidMax;
            prevRightMax = currentRightMax;
        }
    }

    cout << max(max(currentLeftMax, currentMidMax), currentRightMax) << " " << min(min(currentLeftMin, currentMidMin), currentRightMin) << endl;

    return 0;
}