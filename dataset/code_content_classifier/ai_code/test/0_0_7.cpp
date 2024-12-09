#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findMinChanges(string a, string b) {
    int changes = 0;
    for (int i = 0; i < b.length(); i++) {
        if (a[i] != b[i]) {
            changes++;
        }
    }
    return changes;
}

int main() {
    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    vector<int> results;

    for (int k = 0; k <= n - m + 1; k++) {
        int minChanges = INT_MAX;
        for (int i = 0; i <= n - m; i++) {
            string sub = a.substr(i, m);
            if (sub.length() < m) break;
            minChanges = min(minChanges, findMinChanges(sub, b));
        }
        results.push_back(minChanges);
    }

    for (int result : results) {
        cout << result << " ";
    }

    return 0;
}