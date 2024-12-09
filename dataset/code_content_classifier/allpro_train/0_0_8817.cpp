#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct State {
    vector<int> puzzle;
    int space;
    int moves;

    State(vector<int> puzzle, int space, int moves) : puzzle(puzzle), space(space), moves(moves) {}
};

int solvePuzzle(vector<int> puzzle) {
    queue<State> q;
    map<vector<int>, bool> visited;

    q.push(State(puzzle, 11, 0));
    visited[puzzle] = true;

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (current.puzzle == vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}) {
            return current.moves;
        }

        int x = current.space % 3;
        int y = current.space / 3;

        for (int i = 0; i < 4; i++) {
            int nx = x + vector<int>{0, 1, 0, -1}[i];
            int ny = y + vector<int>{-1, 0, 1, 0}[i];
            int ns = ny * 3 + nx;

            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 4) {
                vector<int> newPuzzle = current.puzzle;
                swap(newPuzzle[current.space], newPuzzle[ns]);

                if (!visited[newPuzzle]) {
                    visited[newPuzzle] = true;
                    q.push(State(newPuzzle, ns, current.moves + 1));
                }
            }
        }
    }

    return -1;
}

int main() {
    int p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13;

    while (true) {
        cin >> p1;
        if (p1 == -1) break;

        cin >> p2 >> p3 >> p4;
        cin >> p5 >> p6 >> p7 >> p8;
        cin >> p9 >> p10 >> p11;
        cin >> p12;
        cin >> p13;

        vector<int> puzzle = {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13};

        int moves = solvePuzzle(puzzle);

        if (moves == -1 || moves > 20) {
            cout << "NA" << endl;
        } else {
            cout << moves << endl;
        }
    }

    return 0;
}