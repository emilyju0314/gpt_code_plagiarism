#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> strengths;
    for (int i = 2; i <= 2*n; ++i) {
        for (int j = 1; j < i; ++j) {
            int strength;
            cin >> strength;
            strengths.push_back(make_pair(strength, make_pair(i, j)));
        }
    }

    sort(strengths.rbegin(), strengths.rend());

    vector<int> teammates(2*n+1, 0);
    vector<bool> taken(2*n+1, false);

    for (auto s : strengths) {
        int person1 = s.second.first;
        int person2 = s.second.second;

        if (!taken[person1] && !taken[person2]) {
            teammates[person1] = person2;
            teammates[person2] = person1;
            taken[person1] = true;
            taken[person2] = true;
        }
    }

    for (int i = 1; i <= 2*n; ++i) {
        cout << teammates[i] << " ";
    }

    return 0;
}