#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<int> seq(n);
    for(int i = 0; i < n; i++) {
        char op;
        cin >> op;
        if(op == '+') {
            int x;
            cin >> x;
            seq[i] = x;
        } else {
            seq[i] = 0;
        }
    }

    long long result = 0;

    for(int i = 0; i < (1 << n); i++) {
        int sum = 0;
        multiset<int> T;

        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                if(seq[j] != 0) {
                    T.insert(seq[j]);
                } else {
                    if(!T.empty()) {
                        auto it = T.begin();
                        T.erase(it);
                    }
                }
            }
        }

        for(int num : T) {
            sum += num;
            sum %= MOD;
        }

        result += sum;
        result %= MOD;
    }

    cout << result << endl;

    return 0;
}