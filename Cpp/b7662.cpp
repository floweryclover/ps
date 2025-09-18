#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<int, int> cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int k;
        cin >> k;

        cnt.clear();
        priority_queue<int> maxQ;
        priority_queue<int, vector<int>, greater<int>> minQ;
        for (int i = 0; i < k; ++i)
        {
            char op;
            int num;
            cin >> op >> num;
            if (op == 'I')
            {
                maxQ.push(num);
                minQ.push(num);
                ++cnt[num];
            }
            else if (num == 1)
            {
                while (!maxQ.empty())
                {
                    const int value = maxQ.top();
                    maxQ.pop();
                    if (cnt[value] > 0)
                    {
                        --cnt[value];
                        break;
                    }
                }
            }
            else
            {
                while (!minQ.empty())
                {
                    const int value = minQ.top();
                    minQ.pop();
                    if (cnt[value] > 0)
                    {
                        --cnt[value];
                        break;
                    }
                }
            }
        }

        bool minValid = false;
        bool maxValid = false;
        int minimum, maximum;
        while (!maxQ.empty())
        {
            const int value = maxQ.top();
            maxQ.pop();
            if (cnt[value] > 0)
            {
                --cnt[value];
                maximum = value;
                maxValid = true;
                break;
            }
        }
        while (!minQ.empty())
        {
            const int value = minQ.top();
            minQ.pop();
            if (cnt[value] > 0)
            {
                --cnt[value];
                minimum = value;
                minValid = true;
                break;
            }
        }

        if (!minValid && !maxValid)
        {
            cout << "EMPTY\n";
        }
        else if (maxValid && minValid)
        {
            cout << maximum << " " << minimum << "\n";
        }
        else
        {
            cout << maximum << " " << maximum << "\n";
        }
    }

    return 0;
}