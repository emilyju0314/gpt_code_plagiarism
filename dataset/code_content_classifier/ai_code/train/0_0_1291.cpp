#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(1 << N);
    for(int i = 0; i < (1 << N); i++) {
        cin >> A[i];
    }
    
    while(N > 0) {
        vector<int> newA;
        for(int i = 0; i < A.size(); i += 2) {
            if(A[i] > A[i + 1]) {
                newA.push_back(A[i] - A[i + 1]);
            } else {
                newA.push_back(A[i + 1] - A[i]);
            }
        }
        A = newA;
        N--;
    }
    
    cout << A[0] << endl;
    
    return 0;
}