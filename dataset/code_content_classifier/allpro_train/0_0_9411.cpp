#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    fflush(stdout);
    int result;
    cin >> result;
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> p(n), b(n);
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        p[i] = query(0, i);
    }

    for (int i = 0; i < n; i++) {
        b[i] = query(i, 0);
    }

    cout << "!" << endl;

    int answer_cnt = 0;
    vector<int> perm;

    do {
        bool valid = true;
        for (int i = 0; i < n; i++) {
            if ((p[0] ^ b[i]) != a[i]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            answer_cnt++;
            perm = p;
        }
    } while(next_permutation(p.begin(), p.end()));

    cout << answer_cnt << endl;
    for (int i = 0; i < n; i++) {
        cout << perm[i] << " ";
    }
    cout << endl;

    return 0;
}