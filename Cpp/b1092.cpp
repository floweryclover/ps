#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<int> cranes; // [i] = M : i번째 크레인의 무게 제한: M
    int m;
    priority_queue<int> packages;

    cin >> n;
    for (int i=0; i<n; i++)
    {
        int input;
        cin >> input;
        cranes.push_back(input);
    }
    sort(cranes.begin(), cranes.end());

    cin >> m;
    for (int i=0; i<m; i++)
    {
        int input;
        cin >> input;
        packages.push(input);
    }

    vector<int> works(n, 0);
    while (!packages.empty())
    {
        auto currentPkg = packages.top();
        packages.pop();
        int minCrane = 0;
        while (currentPkg > cranes[minCrane] && minCrane < cranes.size())
            minCrane++;

        if (minCrane >= cranes.size())
        {
            cout << -1 << endl;
            return 0;
        }

        while (minCrane < cranes.size()-1 && works[minCrane]>=works[minCrane+1])
        {
            minCrane++;
        }

        works[minCrane] += 1;
    }

    int largest = 0;
    for (const auto& work : works)
    {
        if (work > largest)
            largest = work;
    }

    cout << largest << endl;
}