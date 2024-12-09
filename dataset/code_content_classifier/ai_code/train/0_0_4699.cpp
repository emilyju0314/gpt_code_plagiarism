#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> commands;
        for (int i = 0; i < n; i++) {
            int t_i, x_i;
            cin >> t_i >> x_i;
            commands.push_back({t_i, x_i});
        }

        int success = 0;
        int currPos = 0;
        int currTime = 0;

        for (int i = 0; i < n; i++) {
            int targetPos = commands[i].second;
            int targetTime = commands[i].first;

            int dist = abs(targetPos - currPos);
            int timeDiff = targetTime - currTime;

            if (timeDiff >= dist) {
                if ((timeDiff - dist) % 2 == 0) {
                    success++;
                }
            }

            currPos = targetPos;
            currTime = targetTime;
        }

        cout << success << endl;
    }

    return 0;
}