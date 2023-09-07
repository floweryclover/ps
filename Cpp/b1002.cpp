#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double distance = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));

        if (x1==x2 && y1==y2)
        {
            if (r1==r2)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else
        {
            if (distance > r1+r2)
            {
                cout << 0 << endl;
            }
            else if (distance == r1+r2)
            {
                cout << 1 << endl;
            }
            else
            {
                if (distance == abs(r2-r1))
                {
                    cout << 1 << endl;
                }
                else if (distance > abs(r2-r1))
                {
                    cout << 2 << endl;
                }
                else
                {
                    cout << 0 << endl;
                }
            }
        }
    }
}