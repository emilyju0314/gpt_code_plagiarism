#include <iostream>
#include <vector>

using namespace std;

void update(vector<int>& A, int s, int t, int x) {
    for (int i = s; i <= t; i++) {
        A[i] = x;
    }
}

int getSum(const vector<int>& A, int s, int t) {
    int sum = 0;
    for (int i = s; i <= t; i++) {
        sum += A[i];
    }
    return sum;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> A(n, 0);

    for (int i = 0; i < q; i++) {
        int type, s, t, x;
        cin >> type >> s >> t;

        if (type == 0) {
            cin >> x;
            update(A, s, t, x);
        } else {
            cout << getSum(A, s, t) << endl;
        }
    }

    return 0;
}