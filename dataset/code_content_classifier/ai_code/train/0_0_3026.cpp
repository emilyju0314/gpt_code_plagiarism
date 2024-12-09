#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> d(N - 1);
    vector<int> g(N);

    for (int i = 0; i < N - 1; i++) {
        cin >> d[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> g[i];
    }

    long long total_cost = 0;

    for (int i = 0; i < N - 1; i++) {
        total_cost += min(d[i], d[i + 1]);
    }

    for (int i = 0; i < N; i++) {
        total_cost += g[i];
    }

    cout << total_cost << endl;

    return 0;
}