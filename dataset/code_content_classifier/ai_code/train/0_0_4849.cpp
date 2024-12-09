#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, q;
vector<int> A;

void add(int s, int t, int x) {
    for (int i = s; i <= t; i++) {
        A[i] += x;
    }
}

int find(int s, int t) {
    int min_val = INT_MAX;
    for (int i = s; i <= t; i++) {
        min_val = min(min_val, A[i]);
    }
    return min_val;
}

int main() {
    cin >> n >> q;
    A.resize(n);

    for (int i = 0; i < q; i++) {
        int query_type, s, t, x;
        cin >> query_type >> s >> t;

        if (query_type == 0) {
            cin >> x;
            add(s, t, x);
        } else {
            cout << find(s, t) << endl;
        }
    }

    return 0;
}