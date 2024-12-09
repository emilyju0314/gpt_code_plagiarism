#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    
    vector<int> c(n), h(n), t(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i] >> h[i] >> t[i];
    }
    
    int q;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        
        int maxHappiness = 0;
        for(int j = 0; j < n; j++) {
            if(t[j] <= a && a <= t[j] + p - 1 && c[j] <= b) {
                maxHappiness = max(maxHappiness, h[j]);
            }
        }
        
        cout << maxHappiness << endl;
    }
    
    return 0;
}