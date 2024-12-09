#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> tasks(N);
    unordered_map<int, unordered_set<int>> dependencies;
    vector<int> indegree(N, 0);
    vector<int> calls(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> tasks[i];
    }

    for (int i = 0; i < M; i++) {
        int T1, T2;
        cin >> T1 >> T2;
        dependencies[T1].insert(T2);
        indegree[T2]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
        calls[i] = tasks[i];
    }

    int coprocessor_calls = 0;
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (tasks[current] == 1) {
            for (int dep : dependencies[current]) {
                calls[dep] = max(calls[dep], calls[current]);

                indegree[dep]--;
                if (indegree[dep] == 0) {
                    q.push(dep);
                }
            }
        } else {
            coprocessor_calls = max(coprocessor_calls, calls[current]);
            for (int dep : dependencies[current]) {
                indegree[dep]--;
                if (indegree[dep] == 0) {
                    q.push(dep);
                }
            }
        }
    }

    cout << coprocessor_calls + 1 << endl;

    return 0;
}