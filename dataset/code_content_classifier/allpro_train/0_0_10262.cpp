#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, r, avg;
    cin >> n >> r >> avg;

    vector<pair<int, int>> exams;
    long long total_points = 0;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        exams.push_back({a, b});
        total_points += a;
    }

    sort(exams.begin(), exams.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    long long essays_needed = 0;
    long long points_needed = (long long)n * avg - total_points;

    for (int i = 0; i < n && points_needed > 0; i++) {
        long long points_to_add = min(points_needed, (long long)(r - exams[i].first));
        essays_needed += points_to_add * exams[i].second;
        points_needed -= points_to_add;
    }

    cout << essays_needed << endl;

    return 0;
}