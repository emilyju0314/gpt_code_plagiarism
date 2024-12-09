#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int b, e, t;
        cin >> b >> e >> t;
        for (int j = 0; j < e - b; j++) {
            swap(A[b + j], A[t + j]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    return 0;
}