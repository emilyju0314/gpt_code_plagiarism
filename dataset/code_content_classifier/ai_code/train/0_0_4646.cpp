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
    
    double max_efficiency = -1;
    
    for (int i = 0; i < n - 2; i++) {
        int j = i + 1;
        
        while (j < n - 1 && energies[j + 1] - energies[i] <= U) {
            j++;
        }
        
        if (j - i >= 2) {
            double efficiency = (double)(energies[j + 1] - energies[j]) / (energies[j + 1] - energies[i]);
            max_efficiency = max(max_efficiency, efficiency);
        }
    }
    
    if (max_efficiency == -1) {
        cout << -1 << endl;
    } else {
        cout << fixed;
        cout.precision(9);
        cout << max_efficiency << endl;
    }
    
    return 0;
}