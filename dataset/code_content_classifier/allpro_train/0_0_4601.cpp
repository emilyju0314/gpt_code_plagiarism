#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int q;
    cin >> q;

    while(q--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> pos;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                pos.push_back(i);
            }
        }

        int cnt = 0;
        for(int i = 0; i < pos.size(); i++) {
            if(k >= pos[i] - i) {
                swap(s[i], s[pos[i]]);
                k -= pos[i] - i;
            } else {
                swap(s[pos[i] - k], s[pos[i]]);
                break;
            }
        }

        cout << s << endl;
    }

    return 0;
}