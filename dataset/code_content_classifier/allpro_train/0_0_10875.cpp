#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> powers(n);
    for (int i = 0; i < n; i++) {
        cin >> powers[i];
    }
    
    sort(powers.begin(), powers.end());
    
    long long int total_power = powers[n-1];
    
    for (int i = n-2; i >= 0; i--) {
        if (powers[i] % total_power == 0) {
            total_power += powers[i];
        } else {
            total_power += powers[i] - (powers[i] % total_power);
        }
    }
    
    cout << total_power << endl;
    
    return 0;
}