#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Problem {
    int resources;
    int scientistID;

    Problem(int r, int id) : resources(r), scientistID(id) {}
};

bool compare(Problem& p1, Problem& p2) {
    return p1.resources < p2.resources;
}

int main() {
    int n;
    cin >> n;

    vector<Problem> problems;
    for (int i = 0; i < n; i++) {
        int k, a, x, y, m;
        cin >> k >> a >> x >> y >> m;

        problems.push_back(Problem(a, i + 1));
        for (int j = 1; j < k; j++) {
            a = ((long long)a * x + y) % m;
            problems.push_back(Problem(a, i + 1));
        }
    }

    sort(problems.begin(), problems.end(), compare);

    int badPairs = 0;
    for (int i = 0; i < problems.size() - 1; i++) {
        if (problems[i].scientistID != problems[i + 1].scientistID) {
            if (problems[i].resources > problems[i + 1].resources) {
                badPairs++;
            }
        }
    }

    cout << badPairs << endl;
    for (auto p : problems) {
        cout << p.resources << " " << p.scientistID << endl;
    }

    return 0;
}