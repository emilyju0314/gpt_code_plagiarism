#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }

    vector<int> visited(n + 1, 0);
    vector<pair<int, int>> instructions;

    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            continue;
        }

        visited[i] = 1;
        int cur = i;
        while (!visited[f[cur]]) {
            cur = f[cur];
            visited[cur] = 1;
        }

        if (f[cur] != i) {
            instructions.push_back({cur, i});
        }
    }

    cout << instructions.size() << endl;
    for (auto instr : instructions) {
        cout << instr.first << " " << instr.second << endl;
    }

    return 0;
}