#include <iostream>
#include <stack>

using namespace std;

constexpr int NONE = -1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;
    input.append("-");

    int lhs = NONE;
    int currentNumber = 0;
    int firstNumber = NONE;
    stack<int> minusStack;
    for (char ch : input)
    {
        if (ch == '+' || ch == '-')
        {
            if (ch == '-')
            {
                
                if (lhs != NONE)
                {
                    if (firstNumber == NONE)
                    {
                        firstNumber = lhs+currentNumber;
                    }
                    else
                    {
                        minusStack.push(lhs + currentNumber);
                    }
                }
                else
                {
                    if (firstNumber == NONE)
                    {
                        firstNumber = currentNumber;
                    }
                    else
                    {
                        minusStack.push(currentNumber);
                    }
                }
                lhs = NONE;
            }
            else if (ch == '+')
            {
                if (lhs != NONE)
                {
                    lhs += currentNumber;
                }
                else
                {
                    lhs = currentNumber;
                }
            }
            currentNumber = 0;
        }
        else
        {
            currentNumber *= 10;
            currentNumber += ch - '0';
        }
    }

    int result = firstNumber;
    while (!minusStack.empty())
    {
        auto top = minusStack.top();
        minusStack.pop();

        result -= top;
    }
    cout << result << endl;
    return 0;
}