#include <iostream>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        cin.ignore();
        
        string operations;
        cin >> operations;

        int arrayLength;
        cin >> arrayLength;
        array<int, 100001> numbers;

        char buf;
        cin >> buf;
        for (int j=0; j<arrayLength; j++)
            cin >> numbers[j] >> buf;

        int begin = 0;
        int end = arrayLength; // exclusive

        bool isError = false;
        for (char operation : operations)
        {
            if (operation == 'R')
            {
                int temp;
                temp = begin;
                begin = end;
                end = temp;
            }
            else
            {
                if (begin == end)
                {
                    isError = true;
                }
                else
                {
                    if (begin < end)
                        begin++;
                    else
                        begin--;
                }
            }
        }
        if (isError)
            cout << "error\n";
        else
        {
            cout << "[";
            if (begin == end)
                cout << "]\n";
            else if (begin < end)
            {

                for (int j=begin; j<end; j++)
                {
                    cout << numbers[j];
                    if (j<end-1)
                        cout << ",";
                    else
                        cout << "]\n";
                }
            }
            else
            {
                for (int j=begin-1; j>=end; --j)
                {
                    cout << numbers[j];
                    if (j>end)
                        cout << ",";
                    else
                        cout << "]\n";
                }
            }
        }
    }

    return 0;
}