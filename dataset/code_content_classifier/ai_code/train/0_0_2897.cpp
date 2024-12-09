#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> friday(n, vector<int>(n));
    vector<vector<int>> saturday(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> friday[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> saturday[i][j];
        }
    }

    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        order[i] = i;
    }

    int max_happiness = 0;
    do {
        int total_happiness = 0;
        for (int i = 0; i < n/2; i++) {
            total_happiness += friday[i][order[i]];
        }
        for (int i = n/2; i < n; i++) {
            total_happiness += saturday[i][order[i]];
        }
        max_happiness = max(max_happiness, total_happiness);
    } while (next_permutation(order.begin(), order.end()));

    cout << max_happiness << endl;

    return 0;
}