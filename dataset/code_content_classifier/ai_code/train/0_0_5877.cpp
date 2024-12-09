#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, a, b, q;
    cin >> n >> a >> b >> q;

    vector<pair<int, char>> hints_a(a); // hints on letters in specified positions
    vector<pair<pair<int, int>, pair<int, int>>> hints_b(b); // hints on duplicated substrings
    vector<int> positions(q); // positions asked

    for (int i = 0; i < a; i++) {
        int x;
        char c;
        cin >> x >> c;
        hints_a[i] = make_pair(x, c);
    }

    for (int i = 0; i < b; i++) {
        int y, h;
        cin >> y >> h;
        hints_b[i] = make_pair(make_pair(y, h), make_pair(0, 0));
    }

    for (int i = 0; i < q; i++) {
        cin >> positions[i];
    }

    string secret_string(n, '?');

    for (auto hint : hints_a) {
        secret_string[hint.first - 1] = hint.second;
    }

    for (auto hint : hints_b) {
        int y = hint.first.first;
        int h = hint.first.second;
        auto sub = secret_string.substr(h, y - h);
        if (h == 0) {
            hint.second.second = y;
            hint.second.first = secret_string.substr(y, n+1-y);
        } 
        secret_string.replace(y, y-hint.second.first.length(), hint.second.first);
    }

    for (int pos : positions) {
        cout << secret_string[pos - 1];
    }
    cout << endl;

    return 0;
}