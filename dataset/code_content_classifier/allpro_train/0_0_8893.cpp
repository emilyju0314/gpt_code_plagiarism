#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> p(N);
    for(int i = 0; i < N; i++) {
        cin >> p[i];
    }

    double sum = 0;
    for(int i = 0; i < K; i++) {
        sum += (p[i] + 1.0) / 2.0;
    }

    double max_sum = sum;
    for(int i = K; i < N; i++) {
        sum = sum - (p[i-K] + 1.0) / 2.0 + (p[i] + 1.0) / 2.0;
        max_sum = max(max_sum, sum);
    }

    cout << fixed << setprecision(12) << max_sum << endl;

    return 0;
}