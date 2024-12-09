#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<string> level(2);
        cin >> level[0];
        cin >> level[1];

        bool possible = true;
        int currentCol = 1; // starting from column 1

        for(int i = 0; i < n; i++) {
            if(level[1][i] == '1') {
                // there is a trap in this cell, cannot go further
                possible = false;
                break;
            }

            if(level[0][i] == '1') {
                // there is a trap in the upper row, try to avoid it if possible
                if(i > 0 && level[1][i-1] == '0') {
                    currentCol = i; // move to the upper row and skip this trap
                } else if(i < n-1 && level[1][i+1] == '0') {
                    currentCol = i + 1; // move to the upper row and skip next trap
                } else {
                    possible = false; // cannot avoid the trap, game over
                    break;
                }
            }

            if(i == n-1 && currentCol != n) {
                // reach the end of the level without reaching the target cell
                possible = false;
                break;
            }
        }

        if(possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}