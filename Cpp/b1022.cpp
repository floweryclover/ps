#include <iostream>

using namespace std;

int GetNumber(int realRow, int realCol)
{
    int currentSquare = max((realRow < 0 ? -realRow : realRow + 1), (realCol <= 0 ? -realCol + 1 : realCol));
    int leftTopNumber = (currentSquare*2)*(currentSquare*2);

    if (realRow == -currentSquare) // 현재 사각형의 맨 위
    {
        int leftOffset = realCol - realRow - 1;
        
        return leftTopNumber - leftOffset;
    }
    else if (realRow > -currentSquare && realRow < currentSquare-1) // 사각형 중간
    {
        int topOffset = realRow + currentSquare;
        if (realCol == -currentSquare+1) // 왼쪽
            return leftTopNumber - ((currentSquare*2)*(currentSquare*2) - ((currentSquare-1)*2)*((currentSquare-1)*2)) + topOffset;
        else // 오른쪽
            return leftTopNumber - (2*currentSquare) + 1 - topOffset;
    }
    else // 맨 밑
    {
        int rightOffset = currentSquare - realCol;

        return leftTopNumber - (2*currentSquare) + 1 - (2*currentSquare) + 1 - rightOffset;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int numbers[50][5];
    int digits[50][5];
    int maxDigit = 1;

    for (int r=0; r<=r2-r1; r++)
    {
        for (int c=0; c<=c2-c1; c++)
        {
            numbers[r][c] = GetNumber(r1+r, c1+c);

            int digit = 1;
            while (numbers[r][c] >= digit*10)
                digit *= 10;

            maxDigit = max(maxDigit, digit);
            digits[r][c] = digit;
        }
    }

    for (int r=0; r<=r2-r1; r++)
    {
        for (int c=0; c<=c2-c1; c++)
        {
            for (int empty=maxDigit; empty > digits[r][c]; empty /= 10)
                cout << " ";
            cout << numbers[r][c];

            if (c == c2-c1)
                cout << "\n";
            else
                cout << " ";
        }
    }

    return 0;
}