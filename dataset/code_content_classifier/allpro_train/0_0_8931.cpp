#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        
        int max_val = max(max(r, g), b);
        int total = r + g + b;
        
        if(max_val <= (total + 1) / 2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}