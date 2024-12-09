#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

struct State {
    vector<int> cards;
    int zeroPos;
    int cost;

    bool operator<(const State& other) const {
        return cost > other.cost;
    }
};

int h(const vector<int>& cards) {
    int res = 0;
    for (int i = 0; i < 8; i++) {
        if (cards[i] != i) {
            res++;
        }
    }
    return res;
}

int astar(const vector<int>& initial) {
    priority_queue<State> pq;
    map<vector<int>, int> visited;

    State start;
    start.cards = initial;
    start.zeroPos = distance(initial.begin(), find(initial.begin(), initial.end(), 0));
    start.cost = h(initial);

    pq.push(start);

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        if (current.cards == vector<int>{0, 1, 2, 3, 4, 5, 6, 7}) {
            return current.cost;
        }

        if (visited.count(current.cards) && visited[current.cards] <= current.cost) {
            continue;
        }

        visited[current.cards] = current.cost;

        static const vector<vector<int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (const auto& move : moves) {
            int newZeroPos = current.zeroPos + move[0] + 4 * move[1];
            if (newZeroPos < 0 || newZeroPos >= 8 || (current.zeroPos % 4) + move[0] < 0 || (current.zeroPos % 4) + move[0] >= 4) {
                continue;
            }

            State next = current;
            swap(next.cards[current.zeroPos], next.cards[newZeroPos]);
            next.zeroPos = newZeroPos;
            next.cost = current.cost + 1 + h(next.cards);

            pq.push(next);
        }
    }

    return -1; // should never reach here
}

int main() {
    vector<int> initial(8);

    while (cin >> initial[0]) {
        for (int i = 1; i < 8; i++) {
            cin >> initial[i];
        }

        cout << astar(initial) << endl;
    }

    return 0;
}