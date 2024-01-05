#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<unsigned long long int, 78> fibonacci;
    fibonacci[0] = 1;
    fibonacci[1] = 1;
    for (int i=2; i<78; i++)
    {
        fibonacci[i] = fibonacci[i-2] + fibonacci[i-1];
    }

    int T;
    cin >> T;
    for (int t=0; t<T; t++)
    {
        int k;
        unsigned long long int x;
        bool found = false;
        cin >> k >> x;

        for (int i=0; i<78; i++)
        {
            if (k==1)
            {
                if (fibonacci[i] == x)
                {
                    found = true;
                    break;
                }
            }
            else
            {
                for (int j=i; j<78; j++)
                {
                    if (k==2)
                    {
                        if (fibonacci[i]+fibonacci[j] == x)
                        {
                            found = true;
                            break;
                        }
                    }
                    else
                    {
                        for (int k=j; k<78; k++)
                        {
                            if (fibonacci[i]+fibonacci[j]+fibonacci[k] == x)
                            {
                                found = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        cout << (found ? "YES" : "NO") << endl;
    }

    return 0;
}