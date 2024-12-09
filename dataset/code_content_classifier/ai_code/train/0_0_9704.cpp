#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000;
const int INF = 2147483647;

vector<int> A(MAX, INF);

void update(int s, int t, int x) {
    for (int i = s; i <= t; i++) {
        A[i] = x;
    }
}

void find(int i) {
    cout << A[i] << endl;
}

int main() {
    int n, q;
    cin >> n >> q;

    while (q--) {
        int query;
        cin >> query;

        if (query == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            update(s, t, x);
        } else {
            int i;
            cin >> i;
            find(i);
        }
    }

    return 0;
}