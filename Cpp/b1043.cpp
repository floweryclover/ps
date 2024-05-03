#include <iostream>
#include <array>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    array<vector<int>, 51> peopleInParties;
    array<bool, 51> peopleKnowTruth;
    array<bool, 51> visited;
    for (int i=0; i<51; i++)
    {
        peopleKnowTruth[i] = false;
        visited[i] = false;
    }

    int truthKnowingPeopleCount;
    cin >> truthKnowingPeopleCount;
    queue<int> search;
    for (int p = 0; p < truthKnowingPeopleCount; p++)
    {
        int person;
        cin >> person;
        search.push(person);
    }

    for (int party = 1; party<=m; party++)
    {
        int peopleCount;
        cin >> peopleCount;

        for (int p = 0; p < peopleCount; p++)
        {
            int person;
            cin >> person;
            peopleInParties[party].push_back(person);
        }
    }

    while (!search.empty())
    {
        auto currentPerson = search.front();
        search.pop();

        if (visited[currentPerson])
            continue;
        visited[currentPerson] = true;
        peopleKnowTruth[currentPerson] = true;

        for (int party=1; party<=m; party++)
        {
            bool isCurrentPersonJoinedThisParty = false;
            for (int person : peopleInParties[party])
            {
                if (person == currentPerson)
                    isCurrentPersonJoinedThisParty = true;
            }
            if (isCurrentPersonJoinedThisParty)
            {
                for (int person : peopleInParties[party])
                {
                    if (!visited[person])
                        search.push(person);
                }
            }
        }
    }

    int exaggerated = m;
    for (int party=1; party<=m; party++)
    {
        bool haveToTellTruth = false;
        for (int person : peopleInParties[party])
        {
            if (peopleKnowTruth[person])
            {
                haveToTellTruth = true;
            }
        }

        if (haveToTellTruth)
            exaggerated--;
    }
    cout << exaggerated << endl;
    return 0;
}