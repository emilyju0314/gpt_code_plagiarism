#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    long long C;
    cin >> n >> m >> C;

    vector<pair<long long, long long>> Vasya_intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> Vasya_intervals[i].first >> Vasya_intervals[i].second;
    }

    vector<pair<long long, long long>> Petya_intervals(m);
    for (int i = 0; i < m; i++) {
        cin >> Petya_intervals[i].first >> Petya_intervals[i].second;
    }

    sort(Vasya_intervals.begin(), Vasya_intervals.end());
    sort(Petya_intervals.begin(), Petya_intervals.end());

    long long Vasya_exp = 0;
    long long Petya_exp = 0;
    long long total_exp = 0;
    long long curr_time = 0;

    for (auto& v : Vasya_intervals) {
        if (v.first > curr_time) {
            curr_time = v.first;
        }
        while (curr_time < v.second) {
            long long boost_time = min(v.second, Petya_intervals.empty() ? 1018 : Petya_intervals.back().second);
            long long boost_exp = min(boost_time - curr_time + 1, C) + 1;
            Vasya_exp += boost_exp;
            total_exp += boost_exp * 2;
            curr_time = boost_time;
            
            while (!Petya_intervals.empty() && curr_time == Petya_intervals.back().second) {
                Petya_intervals.pop_back();
            }
            if (Petya_intervals.empty()) {
                break;
            }
        }
    }

    cout << total_exp << endl;

    return 0;
}