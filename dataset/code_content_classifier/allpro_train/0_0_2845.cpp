#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> A(n), B(m);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    vector<int> prefixA(n+1, 0), prefixB(m+1, 0);
    for (int i = 1; i <= n; i++) {
        prefixA[i] = prefixA[i-1] + A[i-1];
    }
    for (int i = 1; i <= m; i++) {
        prefixB[i] = prefixB[i-1] + B[i-1];
    }

    while (q--) {
        int c;
        cin >> c;

        int count = 0;
        for (int la = 0; la < n; la++) {
            for (int ra = la; ra < n; ra++) {
                for (int lb = 0; lb < m; lb++) {
                    for (int rb = lb; rb < m; rb++) {
                        int sumA = prefixA[ra+1] - prefixA[la];
                        int sumB = prefixB[rb+1] - prefixB[lb];
                        if (abs(sumA - sumB) == c) {
                            count++;
                        }
                    }
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}