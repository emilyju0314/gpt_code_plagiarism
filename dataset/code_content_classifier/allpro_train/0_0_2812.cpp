#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> b(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    
    int steps = 0;
    
    while (true) {
        bool changed = false;
        
        for (int i = 1; i < n-1; i++) {
            int median = (a[i-1] + a[i] + a[i+1]) / 3;
            
            if (b[i] != median) {
                b[i] = median;
                changed = true;
            }
        }
        
        if (!changed) {
            break;
        }
        
        for (int i = 0; i < n; i++) {
            a[i] = b[i];
        }
        
        steps++;
    }
    
    cout << steps << endl;
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    
    return 0;
}