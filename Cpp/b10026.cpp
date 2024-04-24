#include <iostream>
#include <queue>
#include <array>

using namespace std;

array<array<char, 100>, 100> colorMap;
int n;

int Solve(bool isBlind)
{
    int result = 0;

    array<array<bool, 100>, 100> visited;
    for (int i=0; i<100; i++)
        for (int j=0; j<100; j++)
            visited[i][j] = false;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (visited[i][j])
                continue;

            queue<pair<int, int>> search;
            search.emplace(i, j);
            while (!search.empty())
            {
                auto currentY = search.front().first;
                auto currentX = search.front().second;
                auto currentColor = colorMap[currentY][currentX];
                search.pop();

                if (visited[currentY][currentX])
                    continue;
                visited[currentY][currentX] = true;

                auto isCurrentColorSameWith = [currentColor](const bool isBlind, const char color) 
                {
                    if (!isBlind)
                        return currentColor == color;
                    else
                    {
                        return ((currentColor == 'R' || currentColor == 'G') && (color == 'R' || color == 'G')) || (currentColor == 'B' && color == 'B');
                    }
                };

                if (currentY > 0   && isCurrentColorSameWith(isBlind, colorMap[currentY-1][currentX]) && !visited[currentY-1][currentX])
                    search.emplace(currentY - 1, currentX);
                if (currentY < n-1 && isCurrentColorSameWith(isBlind, colorMap[currentY+1][currentX]) && !visited[currentY+1][currentX])
                    search.emplace(currentY + 1, currentX);
                if (currentX > 0   && isCurrentColorSameWith(isBlind, colorMap[currentY][currentX-1]) && !visited[currentY][currentX-1])
                    search.emplace(currentY, currentX - 1);
                if (currentX < n-1 && isCurrentColorSameWith(isBlind, colorMap[currentY][currentX+1]) && !visited[currentY][currentX+1])
                    search.emplace(currentY, currentX + 1);
            }
            result += 1;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            char input;
            cin >> input;

            colorMap[i][j] = input;
        }
    }

    cout << Solve(false) << " " << Solve(true) << endl;
    return 0;
}