#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> beads(n);
    int total_beads = 0;

    for (int i = 0; i < n; i++) {
        cin >> beads[i];
        total_beads += beads[i];
    }

    int max_cuts = 0;

    for (int i = 0; i < n; i++) {
        int cuts_possible = total_beads - beads[i];
        max_cuts = max(max_cuts, min(cuts_possible, beads[i]));
    }

    cout << max_cuts << endl;

    string necklace;

    for (int i = 0; i < total_beads; i++) {
        necklace += char('a' + (i % n));
    }

    cout << necklace << endl;

    return 0;
}