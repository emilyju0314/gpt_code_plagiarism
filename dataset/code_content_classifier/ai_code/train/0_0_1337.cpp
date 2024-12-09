#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> instructions(m);
    for (int i = 0; i < m; i++) {
        cin >> instructions[i].first >> instructions[i].second;
    }

    sort(instructions.begin(), instructions.end());

    vector<int> ans;
    int removed = 0;

    int right = 0;
    for (int i = 0; i < m; i++) {
        if (instructions[i].first > right) {
            ans.push_back(i+1);
        }
        else {
            removed++;
        }
        right = max(right, instructions[i].first + instructions[i].second - 1);
    }

    cout << removed << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}