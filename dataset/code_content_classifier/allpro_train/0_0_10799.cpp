#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(vector<int> b) {
    if (b.size() == 1) {
        return b[0];
    } else {
        vector<int> temp;
        for (int i = 0; i < b.size()-1; i++) {
            temp.push_back(b[i] ^ b[i+1]);
        }
        return f(temp);
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        vector<int> subarray;
        for (int i = l-1; i < r; i++) {
            subarray.push_back(a[i]);
        }
        
        int result = 0;
        for (int i = l-1; i < r; i++) {
            for (int j = i; j < r; j++) {
                vector<int> temp;
                for (int k = i; k <= j; k++) {
                    temp.push_back(a[k]);
                }
                result = max(result, f(temp));
            }
        }
        
        cout << result << endl;
    }
    
    return 0;
}