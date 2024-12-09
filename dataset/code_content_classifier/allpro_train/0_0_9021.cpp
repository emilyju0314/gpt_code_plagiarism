#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> questions(n);
    for(int i = 0; i < n; i++) {
        cin >> questions[i].first >> questions[i].second;
    }

    int q;
    cin >> q;

    vector<pair<int, int>> ranks(q);
    for(int i = 0; i < q; i++) {
        cin >> ranks[i].first >> ranks[i].second;
    }

    int t;
    cin >> t;

    sort(ranks.begin(), ranks.end());

    long long total_solved = 0;
    long long max_solved = 0;
    int max_score = 0;
    int remaining = t;

    for(int i = 0; i < q; i++) {
        long long num_students = ranks[i].first;
        long long score = ranks[i].second;

        if(i == 0) {
            max_solved = num_students;
            max_score = score;
        }

        total_solved += num_students * score;
        remaining -= num_students * score;

        long long potential_solved = total_solved;

        for(int j = 0; j < n; j++) {
            int possible_inc = min(remaining, (long long) questions[j].second * (m - total_solved));
            potential_solved += possible_inc;
        }

        if(potential_solved < t) {
            max_solved = max(max_solved, num_students + 1);
            max_score = score + (remaining - potential_solved + num_students) / (m - total_solved);
            break;
        }
    }

    if(max_solved == 0) {
        cout << "-1 -1" << endl;
    } else {
        cout << max_solved << " " << max_score << endl;
    }

    return 0;
}