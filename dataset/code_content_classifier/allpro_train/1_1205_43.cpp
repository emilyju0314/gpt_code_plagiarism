#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

const int MX = 2097152;
const int HEAD = 1048575;
int A[MX], V[MX];
int n, q;

void init(int n) {
    int l = HEAD + n;
    for (int i=0; i<=l; ++i) {
        A[i] = (i < HEAD ? 1 : i - HEAD);
        V[i] = 0;
    }
    for (int i=l+1; i<MX; ++i) {
        A[i] = INT_MAX;
        V[i] = -INT_MAX;
    }
}

void update(int a, int v) {
    int k = HEAD + a;
    V[k] += v;
    while (k) {
        k = (k - 1) / 2;
        int l = 2*k+1, r = 2*k+2;
        if (V[l] < V[r] || (V[l] == V[r] && A[l] > A[r])) {
            V[k] = V[r];
            A[k] = A[r];
        } else {
            V[k] = V[l];
            A[k] = A[l];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    init(n);
    int a, v;
    for (int i=0; i<q; ++i) {
        cin >> a >> v;
        update(a, v);
        cout << A[0] << " " << V[0] << endl;
    }
    return 0;
}