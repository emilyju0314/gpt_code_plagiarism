#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    while(N--) {
        int L;
        cin >> L;

        vector<int> E(L);
        for(int i = 0; i < L; i++) {
            cin >> E[i];
        }

        int total_energy = 0;
        for(int i = 0; i < L; i++) {
            total_energy += E[i];
        }

        int max_energy = E[0];
        for(int i = 1; i < L; i++) {
            max_energy = max(max_energy, min(total_energy - E[i], E[i]));
        }

        cout << max_energy << endl;
    }

    return 0;
}