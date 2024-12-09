#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    string s, t;
    cin >> n;
    cin >> s;
    cin >> t;

    vector<int> moves;

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            int j = i;
            while (j < n && s[j] != t[i]) {
                j++;
            }

            if (j == n) {
                cout << "-1" << endl;
                return 0;
            }

            for (int k = j - 1; k >= i; k--) {
                swap(s[k], s[k + 1]);
                moves.push_back(k + 1);
            }
        }
    }

    cout << moves.size() << endl;
    for (int i = 0; i < moves.size(); i++) {
        cout << moves[i] << " ";
    }

    return 0;
}