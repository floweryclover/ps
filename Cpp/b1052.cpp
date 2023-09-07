#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n;
    cin >> k;


    int remain = n;
    int count = 0;
    int lastBottle = 0;

    if (n <= k)
    {
        cout << "0" << endl;
        return 0;
    }

    while (count<k)
    {
        if (remain <= 2)
        {
            cout << "0" << endl;
            return 0;
        }

        int power = 1;
        while (power*2 <= remain)
        {
            power *=2 ;
        }

        remain -= power;
        lastBottle = power;
        count++;
    }

    cout << lastBottle-remain << endl;
}