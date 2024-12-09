#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    vector<int> freq(n-1, 0);
    for(int i = 1; i < n; i++) {
        freq[i-1] = A[i] - A[i-1];
    }
    sort(freq.begin(), freq.end());

    int sum = 0;
    for(int i = 0; i < n-k; i++) {
        sum += freq[i];
    }

    cout << sum << endl;

    return 0;
}