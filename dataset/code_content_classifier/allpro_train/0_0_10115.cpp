#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> total_cost(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Calculate the total cost without canceling any spot
    total_cost[0] = abs(A[0]);
    for (int i = 1; i < N; i++) {
        total_cost[i] = total_cost[i-1] + abs(A[i] - A[i-1]);
    }
    total_cost[N-1] += abs(A[N-1]);

    // Calculate the total cost when canceling each spot
    for (int i = 0; i < N; i++) {
        int cost;
        if (i == 0) {
            cost = total_cost[N-1] - abs(A[0]) - abs(A[1] - A[0]);
        } else if (i == N-1) {
            cost = total_cost[N-2] - abs(A[N-2] - A[N-3]) - abs(A[N-1]);
        } else {
            cost = total_cost[N-1] - abs(A[i] - A[i-1]) - abs(A[i+1] - A[i]);
        }
        cout << cost << endl;
    }

    return 0;
}