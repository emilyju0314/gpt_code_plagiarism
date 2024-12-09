#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    vector<int> bugs(m);
    vector<int> abilities(n);
    vector<int> passes(n);

    for(int i = 0; i < m; i++) {
        cin >> bugs[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> abilities[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> passes[i];
    }

    vector<pair<int, int>> students_index;
    for(int i = 0; i < n; i++) {
        students_index.push_back({abilities[i], i + 1});
    }

    sort(students_index.begin(), students_index.end());

    int total_passes = 0;
    vector<int> result(m);

    for(int i = 0; i < m; i++) {
        int bug_complexity = bugs[i];
        int left = 0, right = n;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(students_index[mid].first >= bug_complexity) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if(left == n) {
            cout << "NO" << endl;
            return 0;
        }
        total_passes += passes[students_index[left].second - 1];
        result[i] = students_index[left].second;
    }

    if(total_passes > s) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for(int i = 0; i < m; i++) {
            cout << result[i] << " ";
        }
    }

    return 0;
}