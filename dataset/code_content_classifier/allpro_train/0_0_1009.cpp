#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> difficulties(n);
    for (int i = 0; i < n; i++) {
        cin >> difficulties[i];
    }

    sort(difficulties.begin(), difficulties.end());

    int problems_to_solve = 0;
    for (int i = 0; i < n; i++) {
        if (difficulties[i] <= k) {
            continue;
        }

        int diff = difficulties[i] - k;
        if (diff % 2 == 0) {
            problems_to_solve = max(problems_to_solve, diff / 2);
        } else {
            problems_to_solve = max(problems_to_solve, diff / 2 + 1);
        }
    }

    cout << problems_to_solve << endl;

    return 0;
}