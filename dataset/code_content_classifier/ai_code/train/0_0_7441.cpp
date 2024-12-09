#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> X(N);
    vector<int> Y(N);

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    int median_x = X[N / 2];
    int median_y = Y[N / 2];

    double total_time = 0;

    for (int i = 0; i < N; i++) {
        total_time += abs(X[i] - median_x) + abs(Y[i] - median_y);
    }

    cout << fixed << total_time / 2 << endl;

    return 0;
}