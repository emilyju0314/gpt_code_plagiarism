#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<long long> trash_pos(N);
    for(int i = 0; i < N; i++) {
        cin >> trash_pos[i];
    }

    long long energy = 0;
    // Calculate energy needed to pick up each trash piece and put them in the bin
    for(int i = 0; i < N; i++) {
        energy += (trash_pos[i] * X);
    }

    long long min_energy = energy; // Initialize with the energy when all trash is picked up

    // Evaluate different combinations of carrying trash and reaching to the bin
    for(int k = 1; k < N; k++) {
        long long current_energy = energy; // Current energy needed for this combination
        for(int i = 0; i < N; i++) {
            long long distance = abs(trash_pos[i] - trash_pos[N-k+i]);
            current_energy += (k+1)*(k+1)*distance; // Energy consumed based on the distance and the number of trash carried
        }
        min_energy = min(min_energy, current_energy);
    }

    cout << min_energy << endl;

    return 0;
}