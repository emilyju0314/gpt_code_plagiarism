#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<char> leftPorts(n);
    vector<char> rightPorts(n);
    vector<char> topPorts(m);
    vector<char> bottomPorts(m);

    for(int i = 0; i < n; i++) {
        cin >> leftPorts[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> rightPorts[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> topPorts[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> bottomPorts[i];
    }

    int capacity = 0;
    for(int i = 0; i < n; i++) {
        int redCount = count(leftPorts[i].begin(), leftPorts[i].end(), 'R') + count(rightPorts[i].begin(), rightPorts[i].end(), 'R');
        int blueCount = count(leftPorts[i].begin(), leftPorts[i].end(), 'B') + count(rightPorts[i].begin(), rightPorts[i].end(), 'B');
        capacity += min(redCount, blueCount);
    }

    for(int i = 0; i < m; i++) {
        int redCount = count(topPorts[i].begin(), topPorts[i].end(), 'R') + count(bottomPorts[i].begin(), bottomPorts[i].end(), 'R');
        int blueCount = count(topPorts[i].begin(), topPorts[i].end(), 'B') + count(bottomPorts[i].begin(), bottomPorts[i].end(), 'B');
        capacity += min(redCount, blueCount);
    }

    cout << capacity << endl;

    return 0;
}