
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int N, Q;
    cin >> N;

    vector<pair<int, int>> earthquakes(N);

    for (int i = 0; i < N; i++) {
        int T, A;
        cin >> T >> A;
        earthquakes[i] = make_pair(T, A);
    }

    cin >> Q;

    while (Q--) {
        int L, R;
        cin >> L >> R;

        double performance = 1e9;

        for (int i = 0; i < N; i++) {
            int T = earthquakes[i].first;
            int A = earthquakes[i].second;

            if (T >= R)
                break;

            double p = min(R, T + 1) - max(L, T);
            performance *= pow(0.1, A * p);
        }

        cout << fixed << setprecision(12) << performance << endl;
    }

    return 0;
}