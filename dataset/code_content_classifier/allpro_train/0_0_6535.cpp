#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> room(n);
    for (int i = 0; i < n; i++) {
        cin >> room[i];
    }

    int maxCleanRows = 0;

    for (int i = 0; i < n; i++) {
        int cleanColumns = 0;
        for (int j = 0; j < n; j++) {
            if (room[j][i] == '1') {
                cleanColumns++;
            }
        }
        maxCleanRows = max(maxCleanRows, cleanColumns);
    }

    cout << maxCleanRows << endl;

    return 0;
}