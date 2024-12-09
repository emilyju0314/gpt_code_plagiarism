#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> grid(2);
        for (int i = 0; i < 2; i++) {
            cin >> grid[i];
        }

        int currentCol = 0;
        bool canComplete = true;
        while(currentCol < n - 1) {
            if (grid[1][currentCol+1] == '1' || (currentCol < n - 2 && grid[0][currentCol+2] == '1')) {
                canComplete = false;
                break;
            }
            if (currentCol < n - 2 && grid[1][currentCol+2] == '0') {
                currentCol += 2;
            } else {
                currentCol++;
            }
        }

        if (canComplete) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}