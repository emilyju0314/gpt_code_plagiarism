#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> colors(n);
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    vector<pair<int, int>> instructions(m);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        instructions[i] = make_pair(l, r);
    }

    map<pair<int, int>, int> sockCounts;
    for (auto instr : instructions) {
        sockCounts[{colors[instr.first-1], colors[instr.second-1]}++;
    }

    int maxColorChanges = 0;
    for (auto sockColorPair : sockCounts) {
        maxColorChanges = max(maxColorChanges, sockColorPair.second);
    }

    cout << m - maxColorChanges << endl;

    return 0;
}