#include <iostream>
#include <vector>

using namespace std;

vector<int>::iterator GetBiggestIter(vector<int>::iterator begin, vector<int>::iterator end)
{
    if (begin==end)
    {
        return end;
    }

    vector<int>::iterator biggest = begin;
    for (vector<int>::iterator iter = begin+1; iter <= end; iter++)
    {
        if (*iter > *biggest)
        {
            biggest = iter;
        }
    }
    return biggest;
}

int main()
{
    int n,s;
    cin >> n;
    vector<int> v;

    for (int i=0; i<n; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }

    cin >> s;

    for (int i=0; i<s; i++)
    {
        int range = s-i;
        if (range > v.size()-1)  range = v.size()-1;

        int offset = 0;
        auto biggestIter = v.end();
        while (offset < v.size()-1)
        {
            int last = offset + range;
            if (last >= v.size())
            {
                last = v.size()-1;
            }
            auto iter = GetBiggestIter(v.begin()+offset, v.begin() + last);
            if (iter == v.begin()+offset)
            {
                offset++;
                continue;
            }
            else
            {
                if (*(iter-1) > (*iter))
                {
                    offset++;
                    continue;
                }
                else
                {
                    biggestIter = iter;
                    break;
                }
            }
        }

        if (biggestIter == v.end())
        {
            break;
        }
        else
        {
            iter_swap(biggestIter-1, biggestIter);
        }
    }

    for (const auto& elem : v)
    {
        cout << elem << " ";
    }
}