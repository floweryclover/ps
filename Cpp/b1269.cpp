#include <iostream>
#include <set>

using namespace std;

using Ull = unsigned long long;

set<Ull> A, B;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; ++i)
    {
        Ull input;
        cin >> input;
        A.insert(input);
    }
    for (int i = 0; i < b; ++i)
    {
        Ull input;
        cin >> input;
        B.insert(input);
    }

    int b_a = B.size();
    for (const Ull elem : B)
    {
        if (A.find(elem) != A.end())
        {
            --b_a;
        }
    }

    int a_b = A.size();
    for (const Ull elem : A)
    {
        if (B.find(elem) != B.end())
        {
            --a_b;
        }
    }

    cout << b_a + a_b << endl;

    return 0;
}