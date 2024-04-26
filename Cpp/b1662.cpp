#include <iostream>

using namespace std;

string input;

int Parse(string::const_iterator from, string::const_iterator to)
{
    int length = 0;
    int prev = 0;
    auto iter = from;
    while (iter != to)
    {
        if (*iter == '(')
        {
            length -= 1;
            
            int stack = 1;
            auto closeBracketIter = iter+1;
            for (; closeBracketIter != to; closeBracketIter++)
            {
                if (*closeBracketIter == '(')
                    stack++;
                else if (*closeBracketIter == ')')
                {
                    stack--;
                    if (stack == 0)
                    {
                        break;
                    }
                }
            }
            length += prev * Parse(iter+1, closeBracketIter);
            iter = closeBracketIter+1;
        }
        else
        {
            prev = *iter - '0';
            length++;
            iter++;
        }
    }
    return length;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> input;

    cout << Parse(input.cbegin(), input.cend()) << endl;
    

    return 0;
}