#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <math.h>

using namespace std;

struct System
{
    short cx;
    short cy;
    short r;

    bool operator<(const System& other)
    {
        if (this->r < other.r)
        {
            return true;
        }
        else if (this->r == other.r)
        {
            if (this->cx < other.cx)
            {
                return true;
            }
            else if (this->cx == other.cx)
            {
                return this->cy < other.cy;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    int t;
    cin >> t;
    for (int test=0; test<t; test++)
    {
        short x1, y1, x2, y2, n;
        cin >> x1 >> y1 >> x2 >> y2 >> n;

        vector<System> systems;
        for (int i=0; i<n; i++)
        {
            short cx, cy, r;
            cin >> cx >> cy >> r;

            systems.push_back(System { cx, cy, r });
        }
        sort(systems.begin(), systems.end());

        vector<short> roots;
        for (int i=0; i<n; i++)
        {
            roots.push_back(i);
        }

        for (int smaller=0; smaller<n; smaller++)
        {
            for (int bigger=smaller+1; bigger<n; bigger++)
            {
                if (systems[bigger].r < systems[smaller].r)
                {
                    continue;
                }

                int distance = sqrt(pow(systems[bigger].cy-systems[smaller].cy,2)+pow(systems[bigger].cx-systems[smaller].cx, 2));
                if (systems[bigger].r > distance+systems[smaller].r)
                {
                    roots[smaller]=bigger;
                    break;
                }
            }
        }

        short bRoot=-1;
        short eRoot=-1;
        for (int i=n-1; i>=0; i--)
        {
            int bDist = sqrt(pow(systems[i].cy - y1, 2)+pow(systems[i].cx - x1, 2));
            int eDist = sqrt(pow(systems[i].cy - y2, 2)+pow(systems[i].cx - x2, 2));

            if (systems[i].r > bDist)
                bRoot = i;

            if (systems[i].r > eDist)
                eRoot = i;
        }

        stack<short> b;
        auto root=bRoot;
        while (bRoot!=-1)
        {
            if (root==roots[root])
            {
                b.push(root);
                break;
            }
            b.push(root);
            root=roots[root];
        }
        stack<short> e;
        root=eRoot;
        while (eRoot!=-1)
        {
            if (root==roots[root])
            {
                e.push(root);
                break;
            }
                
            e.push(root);
            root=roots[root];
        }

        if (b.size() == 0 || e.size() == 0)
        {
            cout << b.size() + e.size() << endl;
        }
        else
        {
            auto bTop = b.top();
            auto eTop = e.top();
            while (bTop == eTop)
            {
                b.pop();
                bTop = b.top();
                e.pop();
                eTop = e.top();
                
            }
            cout << b.size() + e.size() << endl;
        }
        
    }
}