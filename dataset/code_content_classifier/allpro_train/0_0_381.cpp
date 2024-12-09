#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    unordered_map<int, int> chainEnds;
    for (int i = 0; i < k; ++i) {
        int m;
        cin >> m;
        int previous, current;
        for (int j = 0; j < m; j++) {
            cin >> current;
            if (j > 0) {
                chainEnds[previous] = current;
            }
            previous = current;
        }
    }

    int totalSeconds = 0;
    for (int i = 1; i <= n; i++) {
        int current = i;
        while (chainEnds.find(current) != chainEnds.end()) {
            current = chainEnds[current];
            totalSeconds++;
        }
    }

    cout << totalSeconds << endl;
    
    return 0;
}