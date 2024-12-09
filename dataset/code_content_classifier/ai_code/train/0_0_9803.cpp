#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> X(N);
    for(int i = 0; i < N; i++) {
        cin >> X[i];
    }

    int A;
    cin >> A;

    vector<int> C(N);
    for(int i = 0; i < N; i++) {
        cin >> C[i];
    }

    int totalWeight = 0;
    for(int i = 0; i < N; i++) {
        totalWeight += X[i];
    }

    int minCost = INT_MAX;
    int currentWeight = K;
    for(int i = 0; i < N; i++) {
        if(X[i] > currentWeight + A) {
            minCost = -1;
            break;
        }

        if(X[i] > currentWeight) {
            minCost = min(minCost, C[i]);
            currentWeight = max(X[i] - A, currentWeight);
        }
    }

    if(totalWeight > currentWeight) {
        minCost = -1;
    }

    cout << minCost << endl;

    return 0;
}