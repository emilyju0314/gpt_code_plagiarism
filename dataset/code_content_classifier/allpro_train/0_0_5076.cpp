#include <iostream>
#include <vector>

using namespace std;

int query_xor(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    int result;
    cin >> result;
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> p(n), b(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        p[i] = query_xor(i, 0);
    }

    b[0] = p[0];
    for (int i = 1; i < n; ++i) {
        b[i] = query_xor(0, i);
    }

    int cnt = 0;
    vector<int> answer;
    for (int x = 0; x < n; ++x) {
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            if ((p[i] ^ b[x]) >= n) {
                valid = false;
                break;
            }
            a[i] = p[i] ^ b[x];
        }
        if (valid) {
            vector<int> tmp(n, -1);
            for (int i = 0; i < n; ++i) {
                if (tmp[a[i]] != -1) {
                    valid = false;
                    break;
                }
                tmp[a[i]] = i;
            }
            if (valid) {
                cnt++;
                answer = a;
            }
        }
    }

    cout << "!" << endl;
    cout << cnt << endl;
    for (int i = 0; i < n; ++i) {
        cout << answer[i] << " ";
    }
    cout << endl;
    cout.flush();

    return 0;
}