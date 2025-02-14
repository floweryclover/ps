#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
    Job(uint16_t t, uint32_t s)
    : T{t}, S{s}
    {}

    uint16_t T;
    uint32_t S;

    bool operator<(const Job& rhs) const
    {
        return S < rhs.S;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Job> jobs;
    jobs.reserve(1000);
    uint32_t latest = 0;
    for (int i=0; i<n; ++i)
    {
        uint16_t t;
        uint32_t s;
        cin >> t >> s;
        jobs.emplace_back(t, s);
        latest = max(latest, s);
    }
    sort(jobs.begin(), jobs.end());

    uint32_t currentTime;
    for (currentTime = latest; currentTime > 0; )
    {
        auto& job = jobs.back();
        if (job.S < currentTime)
        {
            --currentTime;
            continue;
        }

        if (currentTime < job.T)
        {
            break;
        }
        currentTime -= job.T;
        jobs.pop_back();

        if (jobs.empty())
        {
            break;
        }
    }

    if (jobs.empty())
    {
        cout << currentTime << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}