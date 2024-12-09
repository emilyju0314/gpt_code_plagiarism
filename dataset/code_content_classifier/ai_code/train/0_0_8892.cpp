#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {
        int N;
        cin >> N;

        vector<long long> A(N);
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }

        string S;
        cin >> S;

        long long x = 0;
        for(int i = 0; i < N; i++) {
            if(S[i] == '0') {
                x ^= A[i];
            }
        }

        if(x == 0) {
            cout << "0" << endl;
        } else {
            cout << "1" << endl;
        }
    }

    return 0;
}