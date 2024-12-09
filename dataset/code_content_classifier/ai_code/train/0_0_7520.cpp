#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

struct State {
    vector<pair<int, int>> sections;
    int hashCode;

    bool operator<(const State &other) const {
        return sections < other.sections;
    }
};

const vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 1}, {-1, 0}, {0, -1}, {1, -1}};

int getHashCode(const vector<pair<int, int>> &sections) {
    int code = 0;
    for (const auto &section : sections) {
        code = (code << 20) | ((section.first + 1000) << 10) | (section.second + 1000);
    }
    return code;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<pair<int, int>> sections(n);
        for (int i = 0; i < n; i++) {
            cin >> sections[i].first >> sections[i].second;
        }

        int k;
        cin >> k;
        set<pair<int, int>> rocks;
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            rocks.insert({x, y});
        }

        int goalX, goalY;
        cin >> goalX >> goalY;

        queue<State> q;
        State startState = {sections, getHashCode(sections)};
        q.push(startState);

        map<int, int> minMoves;
        minMoves[startState.hashCode] = 0;

        int result = -1;
        while (!q.empty()) {
            State current = q.front();
            q.pop();

            if (current.sections[0].first == goalX && current.sections[0].second == goalY) {
                result = minMoves[current.hashCode];
                break;
            }

            for (int i = 0; i < n; i++) {
                for (const auto &move : moves) {
                    pair<int, int> next = {current.sections[i].first + move.first, current.sections[i].second + move.second};
                    if (rocks.find(next) == rocks.end()) {
                        vector<pair<int, int>> nextSections = current.sections;
                        nextSections[i] = next;
                        State nextState = {nextSections, getHashCode(nextSections)};
                        if (minMoves.find(nextState.hashCode) == minMoves.end()) {
                            minMoves[nextState.hashCode] = minMoves[current.hashCode] + 1;
                            q.push(nextState);
                        }
                    }
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}