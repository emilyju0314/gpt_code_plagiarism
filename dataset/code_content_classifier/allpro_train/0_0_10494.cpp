#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> m(n);
    for(int i = 0; i < n; i++) {
        cin >> m[i];
    }

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        a[i] = m[i];
    }
    
    for(int i = 1; i < n; i++) {
        a[i] = min(a[i], a[i-1]);
    }
    
    for(int i = n-2; i >= 0; i--) {
        a[i] = min(a[i], a[i+1]);
    }
    
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}