#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        char c;
        cin >> n >> c;

        string s;
        cin >> s;

        vector<int> ops;
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (s[i-1] != c) {
                if (n % i == 0) {
                    ops.push_back(i);
                    count++;
                    for (int j = i; j <= n; j += i) {
                        s[j-1] = c;
                    }
                }
            }
        }

        cout << count << endl;
        for (int op : ops) {
            cout << op << " ";
        }
        cout << endl;
    }

    return 0;
}