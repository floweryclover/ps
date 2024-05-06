#include <iostream>

using namespace std;

bool** canvas;

void Draw(const int currentSize, const int totalSize, const int topY, const int topX)
{
    if (currentSize == 3)
    {
        canvas[topY][topX-2] = false; canvas[topY][topX-1] = false; canvas[topY][topX] = true; canvas[topY][topX+1] = false; canvas[topY][topX+2] = false;
        canvas[topY+1][topX-2] = false; canvas[topY+1][topX-1] = true; canvas[topY+1][topX] = false; canvas[topY+1][topX+1] = true; canvas[topY+1][topX+2] = false;
        canvas[topY+2][topX-2] = true; canvas[topY+2][topX-1] = true; canvas[topY+2][topX] = true; canvas[topY+2][topX+1] = true; canvas[topY+2][topX+2] = true;

        return;
    }
    
    Draw(currentSize/2, totalSize, topY, topX);
    Draw(currentSize/2, totalSize, topY+(currentSize/2), topX-(currentSize/2));
    Draw(currentSize/2, totalSize, topY+(currentSize/2), topX+(currentSize/2));\
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    canvas = new bool*[3200];
    for (int i=0; i<3200; i++)
        canvas[i] = new bool[6400];

    Draw(n, n, 0, n-1);

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n*2-1; j++)
            cout << (canvas[i][j] ? "*" : " ");
        cout << "\n";
    }

    for (int i=0; i<3200; i++)
        delete[] canvas[i];
    delete[] canvas;

    return 0;
}