#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    vector<long long> A(N), B(N), C(N), D(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }

    unordered_map<long long, int> AB_sums;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            AB_sums[A[i] + B[j]]++;
        }
    }

    long long count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            long long CD_sum = C[i] + D[j];
            if (AB_sums.find(V - CD_sum) != AB_sums.end()) {
                count += AB_sums[V - CD_sum];
            }
        }
    }

    cout << count << endl;

    return 0;
}