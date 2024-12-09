#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, p, q;
    cin >> n >> p >> q;

    string s;
    cin >> s;

    vector<string> partition;

    for (int i = 0; i <= n; i += p) {
        if ((n - i) % q == 0) {
            int j = (n - i) / q;
            for (int k = 0; k < i/p; k++) {
                partition.push_back(s.substr(k*p, p));
            }
            for (int k = 0; k < j; k++) {
                partition.push_back(s.substr(i + k*q, q));
            }
            cout << partition.size() << endl;
            for (string str : partition) {
                cout << str << endl;
            }
            return 0;
        }
    }

    cout << "-1" << endl;

    return 0;
}