#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    vector<int> sortedP = P;
    sort(sortedP.begin(), sortedP.end());

    int numOps = 0;
    string S = "";
    int t = 0;
    while (P != sortedP && numOps <= 30) {
        S = "";
        t = numOps % 2;
        for (int i = 1; i <= N; i++) {
            if (t == 0) {
                if (P[i - 1] % 2 == 0) {
                    S += '0';
                } else {
                    S += '1';
                }
            } else {
                if (P[i - 1] % 2 == 0) {
                    S += '1';
                } else {
                    S += '0';
                }
            }
        }
        cout << ++numOps << endl;
        cout << t << " " << S << endl;

        vector<int> A, B;
        for (int i = 0; i < N; i++) {
            if (S[i] == '1') {
                if (P[i] % 2 == 0) {
                    A.push_back(P[i]);
                } else {
                    B.push_back(P[i]);
                }
            }
        }

        vector<int> C;
        if (t == 0) {
            for (int num : A) {
                C.push_back(num);
            }
            for (int num : B) {
                C.push_back(num);
            }
        } else {
            for (int num : B) {
                C.push_back(num);
            }
            for (int num : A) {
                C.push_back(num);
            }
        }

        for (int i = 0, j = 0; i < N; i++) {
            if (S[i] == '1') {
                P[i] = C[j];
                j++;
            }
        }
    }

    return 0;
}