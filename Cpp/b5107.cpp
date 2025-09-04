#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int t = 1; ; ++t)
    {
        int N;
        cin >> N;
        if (N == 0)
        {
            break;
        }

        unordered_map<string, string> manitos;
        for (int i = 0; i < N; ++i)
        {
            string from, to;
            cin >> from >> to;

            manitos.emplace(std::move(to), std::move(from));
        }

        int count = 0;
        unordered_set<string> visited;
        for (const auto& [to, _from] : manitos)
        {
            if (visited.find(to) != visited.end())
            {
                continue;
            }
            ++count;

            auto search = &to;
            while (true)
            {
                const auto& from = manitos[*search];
                if (visited.find(from) != visited.end())
                {
                    break;
                }
                visited.insert(from);
                search = &from;
            }
        }

        cout << t << " " << count << "\n";
    }

    return 0;
}