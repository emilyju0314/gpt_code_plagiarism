#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_valid_permutation(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        b[i] = a[i];
    }
    
    do {
        if(is_valid_permutation(a, b)) {
            for(int i = 0; i < n; i++) {
                cout << b[i] << " ";
            }
            cout << endl;
            return 0;
        }
    } while(next_permutation(b.begin(), b.end()));
    
    cout << -1 << endl;
    
    return 0;
}