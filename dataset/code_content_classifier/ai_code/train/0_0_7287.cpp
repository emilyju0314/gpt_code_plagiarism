#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> m(n);
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }
    
    vector<int> a(n); 
    int max_height = 0;
    
    for (int i = 0; i < n; i++) {
        int height = min(max_height + 1, m[i]);
        a[i] = height;
        max_height = height;
    }
    
    for (int i = n-1; i >= 0; i--) {
        int height = min(a[i], max_height);
        a[i] = height;
        max_height = height;
    }
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}