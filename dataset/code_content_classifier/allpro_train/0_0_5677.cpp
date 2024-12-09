#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> energy(n);
    for(int i = 0; i < n; i++) {
        cin >> energy[i];
    }
    
    vector<string> strings(n);
    for(int i = 0; i < n; i++) {
        cin >> strings[i];
    }
    
    long long total_energy = energy[n - 1]; // Initialize total energy with the last string's energy
    for(int i = n - 2; i >= 0; i--) {
        if(strings[i] <= strings[i + 1]) {
            total_energy += energy[i];
        } else {
            int j = i + 1;
            while(j < n && strings[i] > strings[j]) {
                j++;
            }
            if(j == n) {
                cout << -1 << endl;
                return 0;
            }
            i = j - 1; // Update i to next index to avoid double counting
        }
    }
    
    cout << total_energy << endl;
    
    return 0;
}