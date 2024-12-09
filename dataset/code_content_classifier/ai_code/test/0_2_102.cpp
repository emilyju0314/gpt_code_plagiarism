#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        int maxCommands = 0, startRow = 1, startCol = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int row = i, col = j;
                int commands = 0;

                for (char c : s) {
                    if (c == 'L' && col > 1) col--;
                    else if (c == 'R' && col < m) col++;
                    else if (c == 'U' && row > 1) row--;
                    else if (c == 'D' && row < n) row++;
                    commands++;
                }

                if (commands > maxCommands) {
                    maxCommands = commands;
                    startRow = i;
                    startCol = j;
                }
            }
        }

        cout << startRow << " " << startCol << "\n";
    }

    return 0;
}