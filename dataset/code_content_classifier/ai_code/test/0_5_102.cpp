#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        int maxCommands = 0;
        pair<int, int> bestStartingPos;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int currX = i, currY = j;
                int commands = 0;

                for (char c : s) {
                    if (c == 'L') {
                        currY--;
                    } else if (c == 'R') {
                        currY++;
                    } else if (c == 'D') {
                        currX++;
                    } else if (c == 'U') {
                        currX--;
                    }

                    if (currX < 1 || currX > n || currY < 1 || currY > m) {
                        break;
                    }

                    commands++;
                }

                if (commands > maxCommands) {
                    maxCommands = commands;
                    bestStartingPos = make_pair(i, j);
                }
            }
        }

        cout << bestStartingPos.first << " " << bestStartingPos.second << endl;
    }

    return 0;
}