#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, U;
    cin >> n >> U;
    
    vector<int> energies(n);
    for (int i = 0; i < n; i++) {
        cin >> energies[i];
    }

    double maxEfficiency = -1;
    
    for (int i = 0; i < n - 2; i++) {
        int j = i + 1;
        int k = i + 2;
        
        while (k < n) {
            if (energies[k] - energies[i] <= U) {
                double efficiency = (double)(energies[k] - energies[j]) / (energies[k] - energies[i]);
                maxEfficiency = max(maxEfficiency, efficiency);
                k++;
            } else {
                j++;
            }
        }
    }
    
    if (maxEfficiency == -1) {
        cout << -1 << endl;
    } else {
        cout.precision(9);
        cout << fixed << maxEfficiency << endl;
    }

    return 0;
}