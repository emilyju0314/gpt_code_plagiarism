#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> exams;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        exams.push_back(make_pair(a, b));
    }

    sort(exams.begin(), exams.end());

    int day = exams[0].second;

    for (int i = 1; i < n; i++) {
        if (exams[i].second >= day) {
            day = exams[i].second;
        } else {
            day = exams[i].first;
        }
    }

    cout << day << endl;

    return 0;
}