#include <iostream>
#include <vector>
#include <algorithm>
#define M 1000000007
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> powers(n);
    
    for(int i=0; i<n; i++) {
        cin >> powers[i];
    }
    
    long long int total_sum = 0;
    for(int i=0; i<n; i++) {
        total_sum = (total_sum + (long long)powers[i]*powers[(i+1)%n]) % M;
    }
    
    cout << total_sum/2 << endl;
    
    int q;
    cin >> q;
    
    for(int i=0; i<q; i++) {
        int officer, new_power;
        cin >> officer >> new_power;
        
        // Update power of the officer
        powers[officer-1] = new_power;
        
        total_sum = 0;
        for(int j=0; j<n; j++) {
            total_sum = (total_sum + (long long)powers[j]*powers[(j+1)%n]) % M;
        }
        
        cout << total_sum/2 << endl;
    }
    
    return 0;
}