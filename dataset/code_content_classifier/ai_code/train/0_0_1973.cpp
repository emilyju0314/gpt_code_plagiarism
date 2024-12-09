#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    if(A + B > N + 1 || (A == 1 && B == 1 && N > 2)) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> seq;
    for(int i = 0; i < A; i++) {
        seq.push_back(i+1);
    }
    for(int i = 1; i <= B; i++) {
        seq.push_back(N-i+1);
    }

    int num = min(A, B);
    for(int i = num+1; i <= N-A-B+1; i++) {
        seq.push_back(i);
    }

    for(int i = 0; i < N; i++) {
        cout << seq[i] << " ";
    }
    cout << endl;

    return 0;
}