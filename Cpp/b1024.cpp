#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int m, l;
    cin >> m;
    cin >> l;

    for (int len = l; len <= 100; len++)
    {
        if (len == 2 && m % 2 == 0)
            continue;

        if (len % 2 == 0)
        {
            for (int i = m/(len/2)/2 - (len/2)-1; i <= m/(len/2)/2 + (len/2); i++)
            {
                cout << i << " ";
            }
        }
        else
        {
            for (int i= -m/len; i <= m/len; i++)
            {
                cout << m/len + i << " ";
            }
        }
    }
}