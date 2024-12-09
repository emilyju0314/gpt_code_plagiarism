#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, P;
    cin >> N >> P;

    vector<pair<int, int>> members;

    for (int i = 0; i < N; i++) {
        int w, b;
        cin >> w >> b;
        members.push_back({w, b});
    }

    sort(members.begin(), members.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first * 100 - a.first + a.second < b.first * 100 - b.first + b.second;
    });

    int totalWhite = 0;
    int minMembers = 0;

    for (int i = 0; i < N; i++) {
        totalWhite += members[i].first;
        if ((totalWhite * 100) >= (P * (i + 1))) {
            minMembers = i + 1;
        }
    }

    cout << minMembers << endl;

    return 0;
}