#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        string program;
        cin >> program;

        vector<int> table(n, 0);

        set<int> distinctValues;
        for(int i = 0; i < n; i++) {
            if(program[i] == '+') {
                table[i] = table[i - 1] + 1;
            } else {
                table[i] = table[i - 1] - 1;
            }
            distinctValues.insert(table[i]);
        }

        for(int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            l--; r--;

            int left, right;
            if(l == 0) {
                left = 0;
            } else {
                left = table[l - 1];
            }

            right = table[r];

            int result;
            if(l == 0) {
                result = distinctValues.size();
            } else {
                if(left < 0 && right >= 0) {
                    result = distinctValues.size() + left;
                } else {
                    result = distinctValues.size();
                }
            }

            cout << result << endl;
        }
    }

    return 0;
}