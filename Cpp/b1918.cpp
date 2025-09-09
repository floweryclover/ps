#include <iostream>
#include <vector>

using namespace std;

string inOrder;

int GetPriority(const char ch)
{
    switch (ch)
    {
        case '-': case '+':
            return 0;
        case '*': case '/':
            return 1;
        default: // (
            return -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> inOrder;
    inOrder = "(" + inOrder + ")";

    vector<char> operators;
    for (int i = 0; i < inOrder.length(); ++i)
    {
        const char ch = inOrder[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            cout << ch;
            continue;
        }

        if (ch == '(')
        {
            operators.push_back(ch);
        }
        else if (ch == ')')
        {
            while (true)
            {
                const char op = operators.back();
                operators.pop_back();

                if (op == '(')
                {
                    break;
                }
                cout << op;
            }
        }
        else
        {
            while (!operators.empty() && GetPriority(operators.back()) >= GetPriority(ch))
            {
                cout << operators.back();
                operators.pop_back();
            }
            operators.push_back(ch);
        }
    }

    return 0;
}
