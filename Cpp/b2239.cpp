#include <iostream>
#include <array>

using namespace std;

array<array<int, 9>, 9> board;
bool Fill(const int current, array<array<int, 9>, 9>& filled)
{
    if (current >= 81)
    {
        return true;
    }

    const int curX = current % 9;
    const int curY = current / 9;

    if (board[curY][curX] != 0)
    {
        return Fill(current + 1, filled);
    }

    for (int i = 1; i <= 9; ++i)
    {
        auto copy = filled;
        bool available = true;
        const int cellY = curY / 3;
        const int cellX = curX / 3;
        for (int j = 0; j < 9; ++j)
        {
            available = available && filled[j][curX] != i; // row
            available = available && filled[curY][j] != i; // column
            available = available && filled[(cellY * 3) + (j / 3)][(cellX * 3) + (j % 3)] != i; // cell
        }
        if (!available)
        {
            continue;
        }
        copy[curY][curX] = i;

        if (Fill(current + 1, copy))
        {
            filled = copy;
            return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int y = 0; y < 9; ++y)
    {
        string input;
        cin >> input;

        for (int x = 0; x < 9; ++x)
        {
            board[y][x] = input[x] - '0';
        }
    }

    auto fill = board;
    Fill(0, fill);
    for (int y = 0; y < 9; ++y)
    {
        for (int x = 0; x < 9; ++x)
        {
            cout << fill[y][x];
        }
        cout << "\n";
    }

    return 0;
}