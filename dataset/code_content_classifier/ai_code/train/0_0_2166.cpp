#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> sweets(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        sweets[i] = make_pair(a, b);
    }

    vector<pair<int, int>> friends(M);
    for (int j = 0; j < M; j++) {
        int c, d;
        cin >> c >> d;
        friends[j] = make_pair(c, d);
    }

    int max_taste = 0;
    for (int mask = 0; mask < (1 << N); mask++) {
        bool valid = true;
        int total_taste = 0;
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                total_taste += sweets[i].second;
            }
        }

        for (int j = 0; j < M; j++) {
            int total_cost = 0;
            int min_taste = 1000000001;
            for (int i = 0; i < N; i++) {
                if (mask & (1 << i)) {
                    total_cost += sweets[i].first;
                    min_taste = min(min_taste, sweets[i].second);
                }
            }
            if (total_cost >= friends[j].first && min_taste >= friends[j].second) {
                valid = false;
                break;
            }
        }

        if (valid) {
            max_taste = max(max_taste, total_taste);
        }
    }

    cout << max_taste << endl;

    return 0;
}