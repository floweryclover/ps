#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Cmp 
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.second == b.second)
        {
            return a.first > b.first;
        }
        else
        {
            return a.second > b.second;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> minHeap;

    for (int i = 0; i<n; i++)
    {
        int begin, end;
        cin >> begin;
        cin >> end;
        minHeap.push({ begin, end });
    }

    int lastEnd = 0;
    int count = 0;
    while (!minHeap.empty())
    {
        const auto begin = minHeap.top().first;
        const auto end = minHeap.top().second;
        minHeap.pop();

        if (begin < lastEnd)
            continue;

        lastEnd = end;
        count++;
    }

    cout << count << endl;
}