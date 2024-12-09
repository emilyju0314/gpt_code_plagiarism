#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> exams(n);
    for(int i = 0; i < n; i++) {
        cin >> exams[i].first >> exams[i].second;
    }

    sort(exams.begin(), exams.end());

    int day = exams[0].second;
    for(int i = 1; i < n; i++) {
        if(exams[i].second >= day) {
            day = exams[i].second;
        } else {
            day = exams[i].first;
        }
    }

    cout << day << endl;

    return 0;
}