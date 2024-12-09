#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    string song;
    cin >> song;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        string sub = song.substr(l-1, r-l+1);
        
        int length = 0;
        for (char c : sub) {
            length += (c - 'a' + 1) * (r - l + 1);
        }
        cout << length << endl;
    }

    return 0;
}