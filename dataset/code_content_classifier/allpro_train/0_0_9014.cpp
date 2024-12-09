#include <iostream>
#include <vector>

using namespace std;

vector<long long> mCuteSequence(long long a, long long b, long long m) {
    for (int k = 1; k <= 50; k++) {
        vector<long long> seq(k);
        seq[0] = a;
        seq[1] = a + 1;

        bool valid = true;

        for (int i = 2; i < k; i++) {
            seq[i] = 0;
            for (int j = 0; j < i; j++) {
                seq[i] += seq[j];
                if (seq[i] > b) {
                    valid = false;
                    break;
                }
            }
            if (seq[i] + m >= b) break;
        }

        if (valid && seq[k-1] == b) {
            return seq;
        }
    }

    return {};
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        long long a, b, m;
        cin >> a >> b >> m;

        vector<long long> seq = mCuteSequence(a, b, m);

        if (seq.size() == 0) {
            cout << -1 << endl;
        } else {
            cout << seq.size() << " ";
            for (long long num : seq) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}