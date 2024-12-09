#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first - a.second > b.first - b.second;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> students(n);
    for (int i = 0; i < n; i++) {
        cin >> students[i].first >> students[i].second;
    }

    sort(students.begin(), students.end(), compare);

    long long total_dissatisfaction = 0;
    for (int i = 0; i < n; i++) {
        total_dissatisfaction += (long long)students[i].first * i + (long long)students[i].second * (n - 1 - i);
    }

    cout << total_dissatisfaction << endl;

    return 0;
}