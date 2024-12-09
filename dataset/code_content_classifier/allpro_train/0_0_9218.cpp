#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    string genders;
    cin >> genders;

    vector<pair<int, int>> skills(n);

    for (int i = 0; i < n; i++) {
        cin >> skills[i].first;
        skills[i].second = i + 1;
    }

    vector<pair<int, int>> couples;
    int minDiff = INT_MAX;

    for (int i = 0; i < n - 1; i++) {
        if (genders[i] != genders[i+1]) {
              int diff = abs(skills[i].first - skills[i+1].first);
              if (diff < minDiff) {
                  minDiff = diff;
                  couples.clear();
                  couples.push_back({skills[i].second, skills[i+1].second});
              } else if (diff == minDiff) {
                  couples.push_back({skills[i].second, skills[i+1].second});
              }
        }
    }

    cout << couples.size() << endl;
    for (pair<int, int> couple : couples) {
        cout << couple.first << " " << couple.second << endl;
    }

    return 0;
}