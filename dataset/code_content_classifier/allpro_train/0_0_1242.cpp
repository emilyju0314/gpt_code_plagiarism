#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    stack<pair<int, int>> assignments;
    unordered_map<int, int> burlesToRemove;

    int totalBurles = 0;
    int x = 0;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "set") {
            int y, v;
            cin >> y >> v;
            if (y == s) {
                totalBurles += v;
            } else {
                assignments.push({y, v - totalBurles});
            }
        } else if (operation == "if") {
            int y;
            cin >> y;
            if (y != x) {
                // Skip the block
                stack<string> block;
                string cmd;
                while (cin >> cmd && cmd != "end") {
                    block.push(cmd);
                }
                int endCount = 1;
                while (endCount > 0) {
                    if (block.top() == "if") {
                        endCount++;
                    } else if (block.top() == "end") {
                        endCount--;
                    }
                    block.pop();
                }
            }
        } else if (operation == "end") {
            if (!assignments.empty()) {
                totalBurles -= assignments.top().second;
                assignments.pop();
            }
        }

        x = assignments.empty() ? 0 : assignments.top().first;
    }

    cout << totalBurles << endl;
    return 0;
}