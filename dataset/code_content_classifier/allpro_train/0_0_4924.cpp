#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> lcp(n);
    int depth = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            depth++;
        } else {
            depth--;
        }
        lcp[i] = depth;
    }

    while (q--) {
        int query;
        cin >> query;
        cout << lcp[query - 1] << endl;
    }

    return 0;
}