#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> movies;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movies.push_back({a, b});
    }

    vector<int> days(32, 0);
    for (int i = 0; i < n; i++) {
        for (int j = movies[i].first; j <= movies[i].second; j++) {
            days[j]++;
        }
    }

    int totalHappiness = 0;
    for (int i = 1; i <= 31; i++) {
        if (days[i] == 1) {
            totalHappiness += 100;
        } else if (days[i] >= 2) {
            totalHappiness += 50;
        }
    }

    cout << totalHappiness << endl;

    return 0;
}