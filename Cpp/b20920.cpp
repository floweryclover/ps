#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;

struct WordData
{
    int Frequency;
    int Length;
    const string* Word;

    WordData(int frequency, int length, const string& word)
    : Frequency{frequency},
    Length{length},
    Word{&word}
    {

    }

    bool operator<(const WordData& rhs) const
    {
        if (Frequency != rhs.Frequency)
        {
            return Frequency < rhs.Frequency;
        }

        if (Length != rhs.Length)
        {
            return Length < rhs.Length;
        }

        auto lhsIter = Word->begin();
        auto rhsIter = rhs.Word->begin();
        while (lhsIter != Word->end() && rhsIter != rhs.Word->end())
        {
            if (*lhsIter != *rhsIter)
            {
                return *lhsIter > *rhsIter;
            }

            ++lhsIter;
            ++rhsIter;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_map<string, int> frequencies;
    string wordInput;
    for (int i=0; i<N; ++i)
    {
        char word[11];
        cin >> word;

        if (strlen(word) < M)
        {
            continue;
        }

        frequencies[word] += 1;
    }

    priority_queue<WordData> priorityQueue;
    for (const auto& [word, frequency] : frequencies)
    {
        priorityQueue.emplace(frequency, word.length(), word);
    }

    while (!priorityQueue.empty())
    {
        const auto& wordData = priorityQueue.top();
        cout << *wordData.Word << "\n";
        priorityQueue.pop();
    }

    return 0;
}