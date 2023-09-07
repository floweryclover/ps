#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int main()
{
    int m, n;
    cin >> m;
    cin >> n;

    vector<int> boxes;
    queue<pair<int, int>> search;
    int untomatoCount = 0;
    for (int i=0; i<m*n; i++)
    {
        int input;
        cin >> input;
        boxes.push_back(input);

        if (input == 1)
        {
            search.push({ i, 0 });
        }
        else if (input == 0)
        {
            untomatoCount++;
        }
    }

    const int undefined = 2147483647;
    unordered_set<int> visited;
    int largest = 0;
    while (!search.empty())
    {
        auto current = search.front();
        search.pop();
        if (visited.find(current.first) != visited.end())
        {
            continue;
        }

        visited.insert(current.first);

        auto r = current.first / m;
        auto c = current.first % m;
        
        if (boxes[current.first] == 0)
        {
            untomatoCount--;

        }

        if (current.second > largest)
        {
            largest = current.second;
        }

        if (r>0 && boxes[(r-1)*m + c] == 0 && visited.find((r-1)*m + c) == visited.end())
        {
            search.push({ (r-1)*m + c, current.second + 1 });
        }
        if (r<n-1 && boxes[(r+1)*m + c] == 0 && visited.find((r+1)*m + c) == visited.end())
        {
            search.push({ (r+1)*m + c, current.second + 1 });
        }
        if (c>0 && boxes[r*m + (c-1)] == 0 && visited.find(r*m + (c-1)) == visited.end())
        {
            search.push({ r*m + (c-1), current.second + 1 });
        } 
        if (c<m-1 && boxes[r*m + (c+1)] == 0 && visited.find(r*m + (c+1)) == visited.end())
        {
            search.push({ r*m + (c+1), current.second + 1 });
        }
    }

    if (untomatoCount > 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << largest << endl;
    }
}