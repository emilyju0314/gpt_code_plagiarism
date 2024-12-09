#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void f(vector<int>& a, int i) {
    if (a[i] == 0) return;
    
    int left = 2*i, right = 2*i+1;
    
    if (a[left] == 0 && a[right] == 0) {
        a[i] = 0;
    } else if (a[left] > a[right]) {
        a[i] = a[left];
        f(a, left);
    } else {
        a[i] = a[right];
        f(a, right);
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int h, g;
        cin >> h >> g;
        
        vector<int> a((1 << h), 0);
        
        for (int i = 1; i < (1 << h); i++) {
            cin >> a[i];
        }
        
        vector<int> remove;
        
        for (int i = 1; i < (1 << h); i++) {
            while (a[i] > 0 && (i < (1 << g) || a[i] > a[i/2])) {
                remove.push_back(i);
                f(a, i);
            }
        }
        
        long long sum = 0;
        for (int i = 1; i < (1 << g); i++) {
            sum += a[i];
        }
        
        cout << sum << endl;
        for (int i = 0; i < remove.size(); i++) {
            cout << remove[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}