#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int g;
    cin >> g;

    set<unsigned int> squares;
    for (int i = 1; i<=50000; i++)
        squares.emplace(i*i);

    bool found = false;
    for (const auto square : squares)
    {
        if (squares.contains(square-g))
        {
            cout << round(sqrt(square)) << endl;
            found = true;
        }
    }

    if (!found)
        cout << "-1" << endl;

    return 0;
}