#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    string S;
    cin >> S;

    while(q--) {
        int i, j, k;
        cin >> i >> j >> k;

        if(k == 1) {
            sort(S.begin() + i - 1, S.begin() + j);
        } else {
            sort(S.begin() + i - 1, S.begin() + j, greater<char>());
        }
    }

    cout << S << endl;

    return 0;
}