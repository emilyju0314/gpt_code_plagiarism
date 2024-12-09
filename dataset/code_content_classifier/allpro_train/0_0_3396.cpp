#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    vector<int> D(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }

    long long total_energy = 0;
    long long max_energy = 0;

    for (int i = 0; i < N; i++) {
        total_energy += A[i];
    }

    // Calculate the potential energy gains by changing E_i to atom i's index
    vector<long long> potential_energy_gains(N-1, 0);
    for (int i = 0; i < N-1; i++) {
        potential_energy_gains[i] = A[i] - D[i] + A[i+1]; // Energy gained if E_i is changed to i
    }

    // Sort the potential energy gains in decreasing order
    sort(potential_energy_gains.rbegin(), potential_energy_gains.rend());

    // Calculate the maximum energy by considering different number of bonds changed
    for (int i = 0; i <= K; i++) {
        long long current_energy = total_energy;
        for (int j = 0; j < i; j++) {
            current_energy += potential_energy_gains[j];
        }
        max_energy = max(max_energy, current_energy);
    }

    cout << max_energy << endl;

    return 0;
}