#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> results(n*(n-1)/2);

    for (int i = 0; i < n*(n-1)/2 - 1; i++) {
        int x, y;
        cin >> x >> y;
        results[i] = make_pair(x, y);
    }

    vector<int> participants(n);
    for (int i = 0; i < n; i++) {
        participants[i] = i+1;
    }

    vector<int> possible_winners;

    do {
        bool valid = true;

        for (int i = 0; i < n*(n-1)/2 - 1; i++) {
            int x = results[i].first;
            int y = results[i].second;

            if (find(participants.begin(), participants.end(), x) < find(participants.begin(), participants.end(), y)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            possible_winners.push_back(participants.back());
        }

    } while (next_permutation(participants.begin(), participants.end()));

    cout << possible_winners[0] << " " << possible_winners[1] << endl;

    return 0;
}