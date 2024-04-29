#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        string input;
        cin >> input;

        if (input == "0")
            break;

        auto leftIter = input.begin();
        auto rightIter = input.end() - 1;

        bool isPalindrome = true;
        while (leftIter <= rightIter)
        {
            if (*leftIter != *rightIter)
            {
                isPalindrome = false;
                break;
            }
            leftIter++;
            rightIter--;
        }

        if (isPalindrome)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}