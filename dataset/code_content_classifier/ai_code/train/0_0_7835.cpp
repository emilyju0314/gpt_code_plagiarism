#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> legs(n);
    for (int i = 0; i < n; i++) {
        cin >> legs[i];
    }
    
    vector<int> energy(n);
    for (int i = 0; i < n; i++) {
        cin >> energy[i];
    }
    
    int maxLegLength = *max_element(legs.begin(), legs.end());
    int maxLegCount = count(legs.begin(), legs.end(), maxLegLength);
    
    if (maxLegCount > n / 2) {
        cout << "0" << endl;
    } else {
        int energyRequired = 0;
        for (int i = 0; i < n; i++) {
            if (legs[i] != maxLegLength) {
                energyRequired += energy[i];
            }
        }
        cout << energyRequired << endl;
    }
    
    return 0;
}