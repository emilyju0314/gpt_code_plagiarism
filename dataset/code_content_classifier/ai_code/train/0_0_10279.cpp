#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long f(vector<int>& A) {
    sort(A.begin(), A.end());
    return (A[A.size()-1] * A[A.size()-2] * A[A.size()-3]);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    int q;
    cin >> q;
    
    while(q--) {
        int type, l, r, x;
        cin >> type >> l >> r >> x;
        
        if(type == 1) {
            vector<int> temp_A = A;
            temp_A[l-1] += x;
            cout << f(temp_A) << endl;
        } else {
            for(int i = l-1; i < r; i++) {
                A[i] += x;
            }
        }
    }
    
    return 0;
}