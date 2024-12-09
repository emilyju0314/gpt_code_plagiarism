#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<int> possible_values;
        for (int k = 1; k <= n; k++) {
            bool possible = true;
            
            for (int i = 0; i < n; i++) {
                int cnt = 0;
                
                for (int j = 0; j < k; j++) {
                    if (((a[i] & a[(i+j)%n]) == a[(i+j)%n]) && i != (i+j)%n) {
                        cnt++;
                    }
                }
                
                if (cnt == k) {
                    possible = false;
                    break;
                }
            }
            
            if (possible) {
                possible_values.push_back(k);
            }
        }
        
        for (int i = 0; i < possible_values.size(); i++) {
            cout << possible_values[i] << " ";
        }
        
        cout << endl;
    }

    return 0;
}