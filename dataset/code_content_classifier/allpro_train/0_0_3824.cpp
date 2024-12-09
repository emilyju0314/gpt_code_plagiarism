#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int countIntegerIntersectionPoints(vector<int> dlsLines, vector<int> jlsLines) {
    unordered_map<int, int> slopeCount;

    for (int dlsLine : dlsLines) {
        slopeCount[dlsLine]++;
    }

    int count = 0;

    for (int jlsLine : jlsLines) {
        if (slopeCount.find(jlsLine) != slopeCount.end()) {
            count += slopeCount[jlsLine];
        }
    }

    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> dlsLines(n);

        for (int i = 0; i < n; i++) {
            cin >> dlsLines[i];
        }

        int m;
        cin >> m;
        vector<int> jlsLines(m);

        for (int i = 0; i < m; i++) {
            cin >> jlsLines[i];
        }

        cout << countIntegerIntersectionPoints(dlsLines, jlsLines) << endl;
    }

    return 0;
}