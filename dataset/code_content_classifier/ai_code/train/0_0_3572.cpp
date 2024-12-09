#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

int N, M, T;
vector<pair<int, int>> edges;
int changes = 0;
vector<string> changes_made;

bool canReach(int start, int end, const vector<pair<int, int>>& graph) {
    unordered_set<int> visited;
    vector<int> stack;
    stack.push_back(start);
    while (!stack.empty()) {
        int current = stack.back();
        stack.pop_back();
        visited.insert(current);
        for (const auto& edge : graph) {
            if (edge.first == current && edge.second == end) return false;
            if (edge.first == current && visited.find(edge.second) == visited.end()) {
                stack.push_back(edge.second);
            }
        }
    }
    return true;
}

void removeCycleEdges() {
    vector<pair<int, int>> temp;
    for (const auto& edge : edges) {
        if (canReach(edge.second, edge.first, temp)) {
            temp.push_back(edge);
        } else {
            changes_made.push_back("- " + to_string(edge.first) + " " + to_string(edge.second));
            changes++;
        }
    }
    edges = temp;
}

int main() {
    cin >> N >> M >> T;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    removeCycleEdges();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j && canReach(j, i, edges)) {
                edges.push_back({j, i});
                changes_made.push_back("+ " + to_string(j) + " " + to_string(i));
                changes++;
            }
        }
    }

    cout << changes << "\n";
    for (const auto& change : changes_made) {
        cout << change << "\n";
    }

    for (int t = 0; t < T; t++) {
        set<int> remaining;
        for (int i = 1; i <= N; i++) {
            remaining.insert(i);
        }
        
        int count = N;
        while (remaining.size() > 1) {
            vector<int> query;
            for (int r : remaining) {
                query.push_back(r);
                count--;
                if (count == 0 || query.size() == 20) {
                    break;
                }
            }

            cout << "? " << query.size();
            for (int q : query) {
                cout << " " << q;
            }
            cout << endl;

            string response;
            cin >> response;

            if (response == "Win" || response == "Draw") {
                for (int r : query) {
                    remaining.erase(r);
                }
                count = N;
            } 
        }

        cout << "! " << *remaining.begin() << endl;

        string result;
        cin >> result;
        if (result != "Correct") {
            return 0;
        }
    }

    return 0;
}