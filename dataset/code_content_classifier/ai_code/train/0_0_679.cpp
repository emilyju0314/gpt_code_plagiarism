#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

struct State {
    vector<int> board;
    int cost;
    int heuristic;

    bool operator<(const State& other) const {
        return cost + heuristic > other.cost + other.heuristic;
    }
};

int calculateManhattanDistance(int a, int b) {
    int aRow = a / 3, aCol = a % 3;
    int bRow = b / 3, bCol = b % 3;
    return abs(aRow - bRow) + abs(aCol - bCol);
}

int calculateHeuristic(const vector<int>& board) {
    int heuristic = 0;
    for (int i = 0; i < 9; ++i) {
        if (board[i] != 0) {
            heuristic += calculateManhattanDistance(i, board[i] - 1);
        }
    }
    return heuristic;
}

int solvePuzzle(const vector<int>& start, const vector<int>& goal, int ch, int cv) {
    priority_queue<State> pq;
    unordered_map<vector<int>, int> costMap;

    pq.push({start, 0, calculateHeuristic(start)});
    costMap[start] = 0;

    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();

        if (cur.board == goal) {
            return cur.cost;
        }

        int emptyPos = distance(cur.board.begin(), find(cur.board.begin(), cur.board.end(), 0));
        static const vector<int> moves = {1, -1, 3, -3};

        for (int move : moves) {
            int newPos = (emptyPos + move + 9) % 9;
            vector<int> newBoard = cur.board;
            swap(newBoard[emptyPos], newBoard[newPos]);

            int newCost = cur.cost + (move == 1 || move == -1 ? ch : cv);
            if (!costMap.count(newBoard) || newCost < costMap[newBoard]) {
                costMap[newBoard] = newCost;
                pq.push({newBoard, newCost, calculateHeuristic(newBoard)});
            }
        }
    }

    return -1;
}

int main() {
    int ch, cv;
    while (true) {
        cin >> ch >> cv;
        if (ch == 0 && cv == 0) {
            break;
        }

        vector<int> start(9), goal(9);
        for (int i = 0; i < 9; ++i) {
            cin >> start[i];
        }
        for (int i = 0; i < 9; ++i) {
            cin >> goal[i];
        }

        cout << solvePuzzle(start, goal, ch, cv) << endl;
    }

    return 0;
}