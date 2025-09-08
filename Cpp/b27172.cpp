#include <iostream>
#include <cstring>

using namespace std;

int N;
bool exists[1000001];
int cards[100001];
int cardWins[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(exists, 0, sizeof(exists));
    memset(cardWins, 0, sizeof(cardWins));

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int card;
        cin >> card;
        exists[card] = true;
        cards[i] = card;
    }

    for (int i = 1; i <= N; ++i)
    {
        const int card = cards[i];
        for (int j = card + card; j <= 1000001; j += card)
        {
            if (exists[j])
            {
                cardWins[j] -= 1;
                cardWins[card] += 1;
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        cout << cardWins[cards[i]] << " ";
    }

    return 0;
}