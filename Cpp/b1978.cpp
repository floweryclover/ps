#include <iostream>

using namespace std;

bool IsPrime(int number)
{
    if (number == 1)
        return false;
    else if (number == 2)
        return true;

    if (number%2 == 0)
        return false;
    for (int i=3; i<number; i+=2)
    {
        if (number%i == 0)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int count = 0;
    for (int i=0; i<n; i++)
    {
        int input;
        cin >> input;
        if (IsPrime(input))
            count++;
    }

    cout << count << endl;

    return 0;
}