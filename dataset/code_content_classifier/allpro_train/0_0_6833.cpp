#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double calculateProbability(int N, int L, vector<int> P, vector<int> T, vector<int> V) {
    vector<double> probability(N, 0.0);
    probability[0] = 1.0;

    for (int i = 0; i < N; i++) {
        double p = P[i] / 100.0;
        double t = T[i];
        double v = V[i];

        for (int j = 1; j <= L / v; j++) {
            double currentProbability = 0.0;

            for (int k = 1; k <= M; k++) {
                double breakProbability = 1.0 - pow((1.0 - p), j);
                double restTime = t * k;

                if (j >= restTime) {
                    currentProbability += breakProbability * probability[(i - 1 + N) % N];
                }
            }

            probability[i] += currentProbability * pow((1.0 - p), j) * pow(p, j - 1);
        }
    }

    return probability[N - 1];
}

int main() {
    int N, M, L;
    cin >> N >> M >> L;

    vector<int> P(N), T(N), V(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i] >> T[i] >> V[i];
    }

    cout << fixed << setprecision(8);
    for (int i = 0; i < N; i++) {
        cout << calculateProbability(N, L, P, T, V) << endl;
    }

    return 0;
}