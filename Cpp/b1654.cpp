#include <iostream>
#include <array>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    array<unsigned long long, 10000> cables;
    unsigned long long low = 1;
    unsigned long long high = 0;
    for (int i=0; i<k; i++)
    {
        unsigned long long input;
        cin >> input;
        cables[i] = input;
        high = max(high, input);
    }

    while (low <= high)
    {
        unsigned long long mid = (high+low)/2;
        int count = 0;
        for (int i=0; i<k; i++)
            count += cables[i]/mid;

        if (count >= n)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << high << endl;

    return 0;
}