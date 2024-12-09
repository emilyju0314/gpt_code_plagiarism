#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> starMap(n);
    for (int i = 0; i < n; i++) {
        cin >> starMap[i];
    }

    int count = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (starMap[i][j] == '*') {
                int radius = 1;
                while (i - radius >= 0 && i + radius < n && 
                       j - radius >= 0 && j + radius < m &&
                       starMap[i - radius][j] == '*' &&
                       starMap[i + radius][j] == '*' &&
                       starMap[i][j - radius] == '*' &&
                       starMap[i][j + radius] == '*') {
                    count++;
                    if (count == k) {
                        cout << i + 1 << " " << j + 1 << endl;
                        cout << i - radius + 1 << " " << j + 1 << endl;
                        cout << i + radius + 1 << " " << j + 1 << endl;
                        cout << i + 1 << " " << j - radius + 1 << endl;
                        cout << i + 1 << " " << j + radius + 1 << endl;
                        return 0;
                    }
                    radius++;
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}