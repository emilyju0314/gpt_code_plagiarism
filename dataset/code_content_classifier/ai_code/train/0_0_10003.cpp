#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    int maxCliqueSize = 1;
    for(int i = 0; i < n; i++) {
        int count = 1;
        for(int j = 0; j < n; j++) {
            if(i != j && (A[i] % A[j] == 0 || A[j] % A[i] == 0)) {
                count++;
            }
        }
        maxCliqueSize = max(maxCliqueSize, count);
    }
    
    cout << maxCliqueSize << endl;
    
    return 0;
}