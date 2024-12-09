#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> obelisks(n);
    vector<pair<int, int>> clues(n);

    for (int i = 0; i < n; i++) {
        cin >> obelisks[i].first >> obelisks[i].second;
    }

    for (int i = 0; i < n; i++) {
        cin >> clues[i].first >> clues[i].second;
    }

    int tx = obelisks[0].first + clues[0].first;
    int ty = obelisks[0].second + clues[0].second;

    cout << tx << " " << ty << endl;

    return 0;
}