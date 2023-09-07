#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<unsigned short> map;
    for (int i=0; i<n; i++)
    {
        string input;
        cin >> input;

        for (auto iter = input.begin(); iter != input.end(); iter++)
        {
            map.push_back(*iter - 48);
        }
    }

    unsigned short count = 0;
    priority_queue<unsigned short, vector<unsigned short>, greater<unsigned short>> countEach;
    unordered_set<unsigned short> visited;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (visited.find(i*n + j) == visited.end())
            {
                if (map[i*n + j] == 1)
                {
                    stack<unsigned short> search;
                    search.emplace(i*n + j);

                    unsigned short buildingCount = 0;
                    while (!search.empty())
                    {
                        auto current = search.top();
                        search.pop();
                        if (visited.find(current) != visited.end())
                            continue;

                        visited.insert(current);
                        buildingCount++;
                        unsigned short currentRow = current / n;
                        unsigned short currentCol = current % n;
                        if (currentRow>0 && map[(currentRow-1)*n + currentCol] == 1 && visited.find((currentRow-1)*n + currentCol) == visited.end()) search.push((currentRow-1)*n + currentCol);
                        if (currentRow<n-1 && map[(currentRow+1)*n + currentCol] == 1 && visited.find((currentRow+1)*n + currentCol) == visited.end()) search.push((currentRow+1)*n + currentCol);
                        if (currentCol>0 && map[(currentRow)*n + currentCol-1] == 1 && visited.find((currentRow)*n + currentCol-1) == visited.end()) search.push((currentRow)*n + currentCol-1);
                        if (currentCol<n-1 && map[(currentRow)*n + currentCol+1] == 1 && visited.find((currentRow)*n + currentCol+1) == visited.end()) search.push((currentRow)*n + currentCol+1);
                    }
                    count++;
                    countEach.push(buildingCount);
                }
            }
        }
    }

    cout << count << endl;

    while (!countEach.empty())
    {
        auto current = countEach.top();
        countEach.pop();
        cout << current << endl;
    }
}