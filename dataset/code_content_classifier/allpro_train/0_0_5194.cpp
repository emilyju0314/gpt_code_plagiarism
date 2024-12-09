#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int X, Y, Z, N, M, S, T;
    cin >> X >> Y >> Z >> N >> M >> S >> T;

    vector<pair<int, int>> sand_cutlet(N);
    vector<pair<int, int>> cutlet_curry(M);

    for (int i = 0; i < N; i++) {
        cin >> sand_cutlet[i].first >> sand_cutlet[i].second;
    }

    for (int i = 0; i < M; i++) {
        cin >> cutlet_curry[i].first >> cutlet_curry[i].second;
    }

    vector<int> curry_count(Z + 1, 0);
    vector<int> curries(M, 0);

    for (int i = 0; i < S; i++) {
        curry_count[sand_cutlet[i].second]++;
    }

    for (int i = 0; i < S; i++) {
        if (curry_count[cutlet_curry[T - 1].second] > 0) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}