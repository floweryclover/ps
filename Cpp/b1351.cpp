#include <iostream>
#include <map>

using namespace std;

long long int A(map<long long, long long>& memo, long long i, long long& P, long long& Q)
{
    if (i == 0)
        return 1;
    else if (memo.find(i) != memo.end())
    {
        return memo[i];
    }
    else
    {
        return memo[i] = A(memo, i/P, P, Q) + A(memo, i/Q, P, Q);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, P, Q;
    cin >> N >> P >> Q;

    map<long long, long long> memo;
    memo[0] = 1;
    cout << A(memo, N, P, Q);
    return 0;
}