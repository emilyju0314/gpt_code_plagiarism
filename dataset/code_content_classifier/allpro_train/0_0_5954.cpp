#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<pair<int, int>> workers(N);
    for (int i = 0; i < N; i++) {
        cin >> workers[i].first >> workers[i].second;
    }

    auto calculateResult = [&](int v, int d) {
        int result = 0;
        while (v != -1 && d > 0) {
            result += workers[v].second;
            v = workers[v].first;
            d--;
        }
        return result;
    };

    for (int i = 0; i < Q; i++) {
        int query_type;
        cin >> query_type;
        if (query_type == 2) {
            int v, d;
            cin >> v >> d;
            cout << calculateResult(v, d) << endl;
        } else {
            // Handle other query types if needed
        }
    }

    return 0;
}