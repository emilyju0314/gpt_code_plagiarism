#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d, S;
    cin >> n >> d >> S;

    vector<pair<int, pair<int, pair<int, int>>> robots;

    for (int i = 0; i < n; i++) {
        int ci, fi, li;
        cin >> ci >> fi >> li;
        robots.push_back({ci, {fi, {li, i + 1}}});
    }

    sort(robots.begin(), robots.end(), greater<pair<int, pair<int, pair<int, int>>>>());

    int fuel_needed = 0;
    int robots_transported = 0;
    vector<int> taken(n + 1, 0);

    for (int i = 0; i < n; i++) {
        if (robots[i].second.second.second < d) {
            taken[robots[i].second.second.second] = 1;
            fuel_needed += robots[i].second.first;
            robots_transported++;
        } else {
            if (fuel_needed + robots[i].second.first <= S) {
                fuel_needed += robots[i].second.first;
                int curr_robot = i;
                while (curr_robot > 0) {
                    if (taken[robots[curr_robot].second.second.second] == 0) {
                        taken[robots[curr_robot].second.second.second] = 1;
                        robots_transported++;
                        break;
                    }
                    curr_robot--;
                }
            }
        }
    }

    cout << robots_transported << " " << fuel_needed << endl;

    return 0;
}