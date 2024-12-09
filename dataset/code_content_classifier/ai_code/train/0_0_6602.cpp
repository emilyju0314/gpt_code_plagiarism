#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> b(k);
    bool hasB = false;
    if(k > 0) {
        hasB = true;
        for(int i = 0; i < k; i++) {
            cin >> b[i];
        }
    }
    
    vector<int> extra;
    int operations = 0;
    int prev = a[0];
    for(int i = 1; i < n; i++) {
        if(hasB && binary_search(b.begin(), b.end(), i + 1)) {
            if(a[i] <= prev) {
                extra.push_back(prev + 1);
                operations++;
            }
        } else {
            if(a[i] <= prev) {
                extra.push_back(prev + 1);
                operations++;
            }
            prev = max(prev, a[i]);
        }
    }
    
    if(operations == 0) {
        cout << 0 << endl;
    } else {
        sort(extra.begin(), extra.end());
        for(int i = 0; i < extra.size(); i++) {
            if(extra[i] == a[i]) {
                operations--;
            }
        }
        cout << operations << endl;
    }
    
    return 0;
}