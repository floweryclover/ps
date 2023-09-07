#include <iostream>
#include <vector>

#include <bitset>

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    vector<long long int> before(n);
    vector<long long int> after(n);

    for (int i = 0; i<n; i++)
    {
        string input;
        cin >> input;
        long long int inputToBinary = (long long int)bitset<64>(input).to_ullong();
        cout << inputToBinary << "\n";
        before[i] = inputToBinary;
    }

    for (int i = 0; i<n; i++)
    {
        int a;
        int input;
        cin >> input;
        after[i] = input;
    }

    for (int i=0; i+2<n; i++)
    {
        for (int j=0; j+2<m; j++)
        {
            long long int r1 = before[i]^after[i];
            long long int r2 = before[i+1]^after[i+1];
            long long int r3 = before[i+2]^after[i+2];
        }
    }
}