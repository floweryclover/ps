#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const char* Mbtis[] = { "ISTJ", "ISFJ", "INFJ", "INTJ", "ISTP", "ISFP", "INFP", "INTP", "ESTP", "ESFP", "ENFP", "ENTP", "ESTJ", "ESFJ", "ENFJ", "ENTJ" };

int Cmp(const string& a, const string& b)
{
    int diff = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (a[i] != b[i])
        {
            ++diff;
        }
    }
    return diff;
}

int Parse(const string& mbti)
{
    for (int i = 0; i < 16; ++i)
    {
        if (Cmp(mbti, Mbtis[i]) == 0)
        {
            return i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<int, string>> dist[16];
    for (int i = 0; i < 16; ++i)
    {
        dist[i].reserve(100'000);
    }
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        for (int i = 0; i < 16; ++i)
        {
            dist[i].clear();
        }

        int N;
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            string student;
            cin >> student;

            for (int j = 0; j < 16; ++j)
            {
                dist[j].emplace_back(Cmp(Mbtis[j], student), student);
            }
        }

        for (int i = 0; i < 16; ++i)
        {
            sort(dist[i].begin(), dist[i].end());
        }

        int minimum = 13;
        for (int i = 0; i < 16; ++i)
        {
            const auto& [cntA, mbtiA] = dist[i][0];
            const auto& [cntB, mbtiB] = dist[i][1];
            const auto& [cntC, mbtiC] = dist[i][2];

            if (cntA > 0)
            {
                continue;
            }

            minimum = min(minimum, cntB + cntC + Cmp(mbtiB, mbtiC));
        }
        cout << minimum << "\n";
    }

    return 0;
}