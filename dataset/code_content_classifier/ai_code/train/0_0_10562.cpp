#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        int pw;
        cin >> pw;

        vector<int> vw(N), pf(N), vf(N), th(N);
        vector<double> min_cost(N, INFINITY);

        for (int i = 0; i < N; i++) {
            cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
        }

        min_cost[0] = 0;

        for (int i = 0; i < N-1; i++) {
            for (int j = th[i]; j > 0; j--) {
                for (int k = 0; k < j; k++) {
                    double F = (th[i+1] - min_cost[i] - vw[i] * (j - k)) / vf[i];
                    if (F >= 0) {
                        double temp_cost = min_cost[i] + pw * (k + (j - k)) + pf[i] * F;
                        min_cost[i+1] = min(min_cost[i+1], temp_cost);
                    }
                }
            }
        }

        double answer = min_cost[N-1];
        cout << fixed;
        cout.precision(4);
        cout << answer << endl;
    }

    return 0;
}