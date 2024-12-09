#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<pair<long long, long long>, long long> a, pair<pair<long long, long long>, long long> b) {
    return a.first.second < b.first.second;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<pair<long long, long long>, long long>> subjects;
    for(int i = 0; i < m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        subjects.push_back({{a, b}, c});
    }

    sort(subjects.begin(), subjects.end(), cmp);

    vector<pair<int, long long>> timetable;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            timetable.push_back({1, subjects[0].first.first});
        } else {
            long long exercises = timetable[i-1].second * k;
            if(i >= subjects.size()) {
                cout << "NO" << endl;
                return 0;
            }
            if(exercises < subjects[i].first.first) {
                cout << "NO" << endl;
                return 0;
            }
            timetable.push_back({i + 1, min(exercises, subjects[i].first.second)});
        }
    }

    cout << "YES" << endl;
    for(auto t : timetable) {
        cout << t.first << " " << t.second << endl;
    }

    return 0;
}