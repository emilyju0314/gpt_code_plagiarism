#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> exams(n);
    for (int i = 0; i < n; i++) {
        cin >> exams[i];
    }

    vector<int> preparation(m);
    for (int i = 0; i < m; i++) {
        cin >> preparation[i];
    }

    vector<int> days_needed(m, 0);
    int total_days = 0;

    for (int i = 0; i < n; i++) {
        if (exams[i] > 0) {
            if (days_needed[exams[i] - 1] == 0) {
                days_needed[exams[i] - 1] = preparation[exams[i] - 1];
            } else {
                days_needed[exams[i] - 1]--;
            }
        }

        total_days++;
    }

    for (int i = 0; i < m; i++) {
        total_days += days_needed[i];
    }

    for (int i = 0; i < m; i++) {
        if (days_needed[i] > 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << total_days << endl;

    return 0;
}