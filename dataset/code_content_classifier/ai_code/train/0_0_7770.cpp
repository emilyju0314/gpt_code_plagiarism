#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long total = 0;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }

    long long target = sum / N;
    long long remain = sum % N;

    for (int i = 0; i < N; i++) {
        long long diff = target - A[i];
        if (diff < 0) {
            total += abs(diff) * remain;
        } else {
            total += diff;
        }
    }

    cout << total << endl;

    return 0;
}