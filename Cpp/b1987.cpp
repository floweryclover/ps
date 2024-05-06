#include <iostream>
#include <array>
#include <queue>

using namespace std;

array<array<char, 20>, 20> board;
int r, c;

using VisitFlag = int;
struct SearchData
{
    char currentX;
    char currentY;
    char visitedCount;
    VisitFlag visitFlag;

    bool IsVisitedAlphabet(char alphabet)
    {
        return visitFlag & (1 << (alphabet - 'A'));
    }

    void SetVisitedAlphabet(char alphabet)
    {
        visitFlag |= (1 << (alphabet - 'A'));
    }
};

int Solve()
{
    array<bool, 26> visitedAlphabetInitial;
    for (int i=0; i<26; i++)
        visitedAlphabetInitial[i] = false;

    queue<SearchData> search;
    search.emplace(SearchData { 0, 0, 0, 0 });

    int maximum = 0;
    while (!search.empty())
    {
        auto currentVisitData = search.front();
        search.pop();

        char alphabetOfCurrentPosition = board[currentVisitData.currentY][currentVisitData.currentX];
        if (currentVisitData.IsVisitedAlphabet(alphabetOfCurrentPosition))
            continue;
        currentVisitData.SetVisitedAlphabet(alphabetOfCurrentPosition);

        currentVisitData.visitedCount += 1;
        maximum = max(maximum, static_cast<int>(currentVisitData.visitedCount));

        if (currentVisitData.currentY > 0 && !currentVisitData.IsVisitedAlphabet(board[currentVisitData.currentY-1][currentVisitData.currentX]))
            search.emplace(SearchData { currentVisitData.currentX, static_cast<char>(currentVisitData.currentY-1), currentVisitData.visitedCount, currentVisitData.visitFlag });
        if (currentVisitData.currentY < r-1 && !currentVisitData.IsVisitedAlphabet(board[currentVisitData.currentY+1][currentVisitData.currentX]))
            search.emplace(SearchData { currentVisitData.currentX, static_cast<char>(currentVisitData.currentY+1), currentVisitData.visitedCount, currentVisitData.visitFlag });
        if (currentVisitData.currentX > 0 && !currentVisitData.IsVisitedAlphabet(board[currentVisitData.currentY][currentVisitData.currentX-1]))
            search.emplace(SearchData { static_cast<char>(currentVisitData.currentX-1), currentVisitData.currentY, currentVisitData.visitedCount, currentVisitData.visitFlag });
        if (currentVisitData.currentX < c-1 && !currentVisitData.IsVisitedAlphabet(board[currentVisitData.currentY][currentVisitData.currentX+1]))
            search.emplace(SearchData { static_cast<char>(currentVisitData.currentX+1), currentVisitData.currentY, currentVisitData.visitedCount, currentVisitData.visitFlag });

    }
    return maximum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;
    for (int i=0; i<r; i++)
        for (int j=0; j<c; j++)
            cin >> board[i][j];

    cout << Solve() << endl;

    return 0;
}