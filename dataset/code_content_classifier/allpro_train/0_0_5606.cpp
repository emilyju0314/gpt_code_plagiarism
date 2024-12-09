#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    vector<int> subordinates(N, 0);
    
    for (int i = 1; i < N; i++) {
        cin >> A[i];
        subordinates[A[i] - 1]++;
    }
    
    for (int i = 0; i < N; i++) {
        cout << subordinates[i] << endl;
    }
    
    return 0;
}