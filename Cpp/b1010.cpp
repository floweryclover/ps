#include <iostream>

using namespace std;

int main()
{
    unsigned long long int t, n, m;
    cin >> t;

    for (int i=0; i<t; i++)
    {
        cin >> n;
        cin >> m;

        unsigned long long int sum = 1;
        for (int j=0; j<n; j++)
        {
            sum *= m;
            m--;
        }

        for (int j=0; j<n; j++)
        {
            sum /= n-j;
        }
        
        cout << sum << endl;
    }
}