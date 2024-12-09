#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int x, a, b, c;

int get_random() {
    int y = (a * x + b) % c;
    x = y;
    return x;
}

int main() {
    int n;
    cin >> n >> x >> a >> b >> c;

    vector<pair<int, string>> teams;
    for (int i = 0; i < n; i++) {
        string name;
        int rating;
        cin >> name >> rating;
        teams.push_back({rating, name});
    }

    sort(teams.begin(), teams.end(), greater<pair<int, string>>());

    char group = 'A';
    int numTeamsPerGroup = n / 4;

    for (int i = 0; i < 4; i++) {
        cout << "Group " << group << ":\n";
        for (int j = 0; j < numTeamsPerGroup; j++) {
            cout << teams[j + i * numTeamsPerGroup].second << endl;
        }
        group++;
    }

    return 0;
}