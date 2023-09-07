#include <iostream>

using namespace std;

short Pack(short kg)
{
    if (kg <= 5)
    {
        if (kg == 5)
        {
            return 1;
        }
        else if (kg == 3)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        if (Pack(kg-5) != -1)
        {
            return 1+Pack(kg-5);
        }
        else if (Pack(kg-3) != -1)
        {
            return 1+Pack(kg-3);
        }
        else
        {
            return -1;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    cout << Pack(n) << "\n";
}