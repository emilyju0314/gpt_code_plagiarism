#include <iostream>
#include <vector>

using namespace std;

int find_answer(int n, vector<int>& a) {
    int res = 0;
    int cur = 0;
    int k = -1;
    for (int i = 0; i < n; i++) {
        cur = cur + a[i];
        if (cur < 0) {
            cur = 0;
            k = i;
        }
        res = max(res, (i - k) * cur);
    }
    return res;
}

int main() {
    int k;
    cin >> k;

    if (k > 1000000) {
        cout << "-1" << endl;
    } else {
        vector<int> a;
        int n = 2000;
        int sum = 0;

        for (int i = 0; i < n-1; i++) {
            a.push_back(1);
            sum += 1;
        }

        a.push_back(k + sum);

        cout << n << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}