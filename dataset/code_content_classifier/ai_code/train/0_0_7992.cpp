#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> b(n+2);
        for(int i = 0; i < n+2; i++) {
            cin >> b[i];
        }
        
        sort(b.begin(), b.end()); // Sort the array to easily identify a_1, a_2, ..., a_n
        
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += b[i];
        }
        
        if(sum == b[n]) { // Check if the sum of a_1, a_2, ..., a_n equals b_{n+1}
            for(int i = 0; i < n; i++) {
                cout << b[i] << " ";
            }
            cout << endl;
        } else {
            sum += b[n];
            sum -= b[n+1]; // Calculate the sum without x
            if(sum == b[n+1]) { // Check if the sum without x equals b_{n+2}
                for(int i = 0; i < n+1; i++) {
                    if(i != n) cout << b[i] << " ";
                }
                cout << endl;
            } else {
                cout << -1 << endl; // If the array b could not be obtained from any array a
            }
        }
    }
    
    return 0;
}