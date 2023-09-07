#include <iostream>
#include <unordered_set>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<unsigned short>> heightMap;
    heightMap.resize(n);
    for (int i=0; i<n; i++)
    {
        heightMap[i].resize(n);
        for (int j=0; j<n; j++)
        {
            unsigned short input;
            cin >> input;
            heightMap[i][j] = input;
        }
    }

    int maxCount = 1;
    for (int rain=1; rain<=100; rain++)
    {
        int count = 0;

        vector<vector<pair<unsigned short, unsigned short>>> roots;
        unordered_set<unsigned short> visited; // row * n + col
        roots.resize(n);
        for (int i=0; i<n; i++)
        {
            roots[i].resize(n);
            for (int j=0; j<n; j++)
            {
                if (visited.find(i*n + j) == visited.end())
                {
                    if (heightMap[i][j] <= rain)
                    {
                        visited.insert(i*n + j);
                    
                    }
                    else
                    {
                        stack<pair<unsigned short, unsigned short>> search;
                        search.push({ i, j });
                        
                        while (!search.empty())
                        {
                            auto current = search.top();
                            search.pop(); 
                            if (visited.find(current.first * n + current.second) != visited.end())
                                continue;

                            visited.insert(current.first * n + current.second);

                            if (current.first>0 && heightMap[current.first-1][current.second] > rain && visited.find((current.first-1)*n + current.second) == visited.end()) search.push({ current.first-1, current.second });
                            if (current.first<n-1 && heightMap[current.first+1][current.second] > rain && visited.find((current.first+1)*n + current.second) == visited.end()) search.push({ current.first+1, current.second });
                            if (current.second>0 && heightMap[current.first][current.second-1] > rain && visited.find((current.first)*n + current.second-1) == visited.end()) search.push({ current.first, current.second-1 });
                            if (current.second<n-1 && heightMap[current.first][current.second+1] > rain && visited.find((current.first)*n + current.second+1) == visited.end()) search.push({ current.first, current.second+1 });
                        }
                        count++;
                    }
                }
            }
        }

        if (count > maxCount)
            maxCount = count;
    }
    cout << maxCount << endl;
}