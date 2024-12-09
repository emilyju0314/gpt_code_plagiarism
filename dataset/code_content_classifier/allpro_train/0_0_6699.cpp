#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string A;
    cin >> A;
    
    string S1, S2;
    
    for (int i = 0; i < n; i++) {
        if (A[i] > A[2*n-1-i]) {
            S1 += A[i];
            A.erase(i, 1);
        } else {
            S1 += A[2*n-1-i];
            A.erase(2*n-1-i, 1);
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (A[i] > A[2*n-1-i]) {
            S2 += A[i];
            A.erase(i, 1);
        } else {
            S2 += A[2*n-1-i];
            A.erase(2*n-1-i, 1);
        }
    }
    
    reverse(S2.begin(), S2.end());
    
    for (int i = 0; i < n; i++) {
        if (S1[i] > S2[i]) {
            cout << 'H';
        } else {
            cout << 'M';
        }
    }
    
    return 0;
}