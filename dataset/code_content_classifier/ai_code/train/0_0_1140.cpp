#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    vector<int> d(n, 0);
    vector<string> lamps(n);

    for (int i = 0; i < n; i++) {
        cout << "? ";
        for (int j = 0; j < n; j++) {
            cout << d[j] << " ";
        }
        cout << endl;
        fflush(stdout);

        for (int j = 0; j < n; j++) {
            cin >> lamps[j];
        }

        for (int j = 0; j < n; j++) {
            if (lamps[j][i] == '0') {
                graph[i].push_back(j);
            }
        }

        d[i]++;
    }

    cout << "!" << endl;
    for (int i = 0; i < n; i++) {
        for (int j : graph[i]) {
            cout << i + 1 << " " << j + 1 << endl;
        }
    }

    return 0;
}