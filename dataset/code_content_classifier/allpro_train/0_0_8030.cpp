#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    long long M = A[N-1];
    vector<pair<int, int>> operations;

    for(int i = 0; i < N-2; i++) {
        operations.push_back({A[N-1], A[i]});
        M -= A[i];
    }

    operations.push_back({A[N-1], M});
    
    cout << M << endl;
    for(auto op : operations) {
        cout << op.first << " " << op.second << endl;
    }    

    return 0;
}