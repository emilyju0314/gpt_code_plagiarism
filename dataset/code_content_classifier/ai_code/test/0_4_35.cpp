#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<char> b(n);
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    int count = 0;
    for(int l = 0; l < n; l++) {
        int x = 1;
        bool isSegmentSimple = true;
        
        for(int r = l; r < n; r++) {
            if(b[r] == '*') {
                x *= a[r];
            } else {
                if(x % a[r] != 0) {
                    isSegmentSimple = false;
                }
                x /= a[r];
            }
            
            if(isSegmentSimple) {
                count++;
            } else {
                break;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}