#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int m;
    cin >> m;

    vector<int> s(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }

    vector<int> seq;
    seq.push_back(s[0]); // The first element of the sequence is the first element of the set

    for (int i = 1; i < m; i++) {
        int common_divisor = gcd(s[i], s[i-1]);
        if (common_divisor != s[i-1]) {
            cout << -1 << endl; // Invalid set, no solution
            return 0;
        }
        seq.push_back(s[i]);
    }

    cout << seq.size() << endl;
    for (int i = 0; i < seq.size(); i++) {
        cout << seq[i] << " ";
    }

    return 0;
}