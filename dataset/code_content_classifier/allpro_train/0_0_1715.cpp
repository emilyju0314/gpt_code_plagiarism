#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    while (true) {
        bool swapped = false;
        for (int i = 0; i < N - 1; i++) {
            if (gcd(A[i], A[i+1]) == 1 && A[i] > A[i+1]) {
                swap(A[i], A[i+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    
    return 0;
}