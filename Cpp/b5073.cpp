#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(true)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c == 0)
        {
            break;
        }

        if (a >= b + c || b >= a + c || c >= a+b)
        {
            cout << "Invalid\n";
        }
        else if (a == b && b == c && c == a)
        {
            cout << "Equilateral\n";
        }
        else if (a == b || b == c || c == a)
        {
            cout << "Isosceles\n";
        }
        else
        {
            cout << "Scalene\n";
        }
    }

    return 0;
}