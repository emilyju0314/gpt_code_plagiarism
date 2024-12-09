#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the number of terms in the specified Farey sequence for a given n
int calculateFareySequence(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++) {
        phi[i] = i;
    }
    
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += phi[i];
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        cout << calculateFareySequence(n) << endl;
    }
    
    return 0;
}