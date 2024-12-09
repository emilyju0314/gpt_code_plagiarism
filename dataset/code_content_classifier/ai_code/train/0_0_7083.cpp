#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<bool> visited(N, false);
    unordered_set<int> cycle;
    int cur = 0;
    while(!visited[cur]) {
        visited[cur] = true;
        cycle.insert(cur);
        cur = a[cur] - 1;
    }

    int cycle_length = 0;
    for(int i = 0; i < N; i++) {
        if(cycle.count(i)) {
            cycle_length++;
        }
    }

    if(K <= cycle_length) {
        cout << K << endl;
    } else {
        cout << cycle_length + (K - cycle_length) * 2 << endl;
    }

    return 0;
}