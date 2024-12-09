#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj_list(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int lifelines = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < adj_list[i].size(); j++) {
            for (int k = j + 1; k < adj_list[i].size(); k++) {
                int v1 = adj_list[i][j];
                int v2 = adj_list[i][k];
                if (i < v1 && i < v2) {
                    lifelines++;
                }
            }
        }
    }

    cout << lifelines << endl;

    return 0;
}