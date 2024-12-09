#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countSubstring(string S, int l, int r, string M) {
    int count = 0;
    for (int i = l; i <= r - M.length(); i++) {
        if (S.substr(i, M.length()) == M) {
            count++;
        }
    }
    return count;
}

int main() {
    string S;
    int Q;
    cin >> S >> Q;

    vector<string> queries(Q);
    for (int i = 0; i < Q; i++) {
        int l, r;
        string M;
        cin >> l >> r >> M;
        cout << countSubstring(S, l, r, M) << endl;
    }

    return 0;
}