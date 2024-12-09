#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<char> b(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    int count = 0;
    
    for (int l = 0; l < n; l++) {
        int x = a[l];
        bool is_simple = true;
        
        for (int r = l; r < n; r++) {
            if (b[r] == '*') {
                x *= a[r+1];
            } else {
                x /= a[r+1];
            }
            
            if (x != (int)x) {
                is_simple = false;
            }
            
            if (is_simple) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}