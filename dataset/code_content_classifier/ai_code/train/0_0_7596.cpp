#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canDivide(int N, vector<string>& graph) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] == '1' && graph[j][i] == '0') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    vector<string> graph(N);
    for (int i = 0; i < N; i++) {
        cin >> graph[i];
    }

    if (!canDivide(N, graph)) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> sets(N, -1);

    int k = 0;
    for (int i = 0; i < N; i++) {
        if (sets[i] == -1) {
            sets[i] = k++;
            for (int j = 0; j < N; j++) {
                if (graph[i][j] == '1' && sets[j] == -1) {
                    sets[j] = k % 2;
                }
            }
        }
    }

    cout << k << endl;

    return 0;
}