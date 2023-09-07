#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n;
    cin >> k;

    vector<int> coins;

    for (int i=0; i<n; i++)
    {
        int input;
        cin >> input;
        coins.push_back(input);
    }

    int count = 0;
    int sum = 0;
    while (sum != k)
    {
        int remain = k-sum;
        int coin = 0;
        for (auto iter = coins.rbegin(); iter != coins.rend(); iter++)
        {
            if ((*iter) <= remain)
            {
                coin = *iter;
                break;
            }
        }

        sum += coin;
        count++;
    }

    cout << count << endl;
}