#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int n;

void inc(int lf, int rg, int v) {
    for (int i = lf; i <= rg; i++) {
        arr[i] += v;
    }
}

int rmq(int lf, int rg) {
    int min_val = INT_MAX;
    for (int i = lf; i <= rg; i++) {
        min_val = min(min_val, arr[i]);
    }
    return min_val;
}

int main() {
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;

        if (op == 0) {
            int lf, rg;
            cin >> lf >> rg;
            cout << rmq(lf, rg) << endl;
        } else {
            int lf, rg, v;
            cin >> lf >> rg >> v;
            inc(lf, rg, v);
        }
    }

    return 0;
}