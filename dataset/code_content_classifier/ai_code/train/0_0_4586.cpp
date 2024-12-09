#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, P;
    cin >> N >> P;

    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    int max_days = 0;
    for (int t = 0; t <= P; t++) {
        int curr_encouragement = P - t;
        int curr_days = 0;
        int curr_motivation = curr_encouragement;

        for (int i = 0; i < N; i++) {
            if (X[i] >= Y[i] + curr_motivation) {
                curr_days++;
                curr_motivation = max(0, curr_motivation - t);
            }
        }

        max_days = max(max_days, curr_days);
    }

    cout << max_days;

    return 0;
}