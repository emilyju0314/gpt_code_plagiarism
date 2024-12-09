#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    long long sum = 0;
    long long maximum_score = 0;
    for (int i = 0; i < K; i++) {
        sum += a[i];
    }
    maximum_score = max(maximum_score, sum);

    for (int i = K; i < N; i++) {
        sum += a[i] - a[i - K];
        maximum_score = max(maximum_score, sum);
    }

    cout << maximum_score << endl;

    return 0;
}