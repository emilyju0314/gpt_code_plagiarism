#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    vector<int> a(n);
    for(int i = 0; i < n-1; i++) {
        a[i] = b[i] - b[i+1];
    }
    
    int last = b[n-1];
    for(int i = 0; i < n; i++) {
        last -= a[i];
    }
    
    bool valid = true;
    for(int i = 0; i < n-1; i++) {
        if(a[i] <= 0) {
            valid = false;
            break;
        }
    }
    
    if(valid && last >= 0) {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}