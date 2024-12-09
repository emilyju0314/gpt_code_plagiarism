#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, int>> spectators;
    int totalAlice = 0, totalBob = 0;

    for (int i = 0; i < n; i++) {
        string views;
        int influence;
        cin >> views >> influence;

        if (views == "10" || views == "11") {
            totalAlice += influence;
        }
        if (views == "01" || views == "11") {
            totalBob += influence;
        }
        spectators.push_back(make_pair(views, influence));
    }

    int half = n / 2 + n % 2;

    sort(spectators.begin(), spectators.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });

    int selectedAlice = 0, selectedBob = 0, selectedTotal = 0;
    for (int i = 0; i < n; i++) {
        if ((selectedAlice < half && (spectators[i].first == "10" || spectators[i].first == "11")) ||
            (selectedBob < half && (spectators[i].first == "01" || spectators[i].first == "11"))) {
            selectedTotal += spectators[i].second;
            if (spectators[i].first == "10" || spectators[i].first == "11") {
                selectedAlice++;
            }
            if (spectators[i].first == "01" || spectators[i].first == "11") {
                selectedBob++;
            }
        }
    }

    if (selectedAlice >= half && selectedBob >= half) {
        cout << selectedTotal << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}