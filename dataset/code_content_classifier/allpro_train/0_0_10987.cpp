#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct State {
    vector<vector<int>> layout;
    int moves;
};

bool isGoalLayout(const vector<vector<int>>& layout) {
    for (int i = 0; i < 4; i++) {
        int suit = layout[i][0] / 10;
        for (int j = 1; j < 7; j++) {
            if (layout[i][j] / 10 != suit || layout[i][j] % 10 != layout[i][j - 1] % 10 + 1) {
                return false;
            }
        }
    }
    return true;
}

int minMovesToGoal(const vector<vector<int>>& initialLayout) {
    queue<State> q;
    unordered_set<vector<vector<int>>> visited;

    State startState = {initialLayout, 0};
    q.push(startState);

    while (!q.empty()) {
        State currState = q.front();
        q.pop();

        if (isGoalLayout(currState.layout)) {
            return currState.moves;
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 1; j < 7; j++) {
                if (currState.layout[i][j] == 0 && currState.layout[i][j-1] != 0) {
                    vector<vector<int>> newLayout = currState.layout;
                    newLayout[i][j] = newLayout[i][j-1] + 1;
                    newLayout[i][j-1] = 0;
                    State newState = {newLayout, currState.moves + 1};
                    if (visited.find(newLayout) == visited.end()) {
                        visited.insert(newLayout);
                        q.push(newState);
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<vector<int>> initialLayout(4, vector<int>(7));
        for (int i = 0; i < 5; i++) {
            if (i > 0) {
                for (int j = 0; j < 7; j++) {
                    cin >> initialLayout[i - 1][j];
                }
            } else {
                string temp;
                getline(cin, temp);
            }
        }

        int minMoves = minMovesToGoal(initialLayout);
        cout << minMoves << endl;
    }

    return 0;
}