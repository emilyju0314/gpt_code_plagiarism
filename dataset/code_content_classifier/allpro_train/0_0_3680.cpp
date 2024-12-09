#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> orig_tri;
    vector<pair<int, int>> goal_tri;

    for (int i = 0; i < n-3; i++) {
        int a, b;
        cin >> a >> b;
        orig_tri.push_back(make_pair(a, b));
    }

    for (int i = 0; i < n-3; i++) {
        int a, b;
        cin >> a >> b;
        goal_tri.push_back(make_pair(a, b));
    }

    vector<pair<int, int>> steps;

    for (int i = n-4; i >= 0; i--) {
        if (orig_tri[i] != goal_tri[i]) {
            steps.push_back(goal_tri[i]);
            orig_tri[i] = goal_tri[i];
        }
    }

    cout << steps.size() << endl;
    for (int i = steps.size() - 1; i >= 0; i--) {
        cout << steps[i].first << " " << steps[i].second << endl;
    }

    return 0;
}