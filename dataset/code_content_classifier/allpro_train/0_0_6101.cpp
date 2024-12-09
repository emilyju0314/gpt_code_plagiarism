#include <iostream>
#include <string>
#include <vector>

using namespace std;

int f(string s) {
    int operations = 0;
    int idx = s.find("..");

    while (idx != string::npos) {
        s.replace(idx, 2, ".");
        operations++;
        idx = s.find("..");
    }

    return operations;
}

int main() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<int> results;

    for (int i = 0; i < m; i++) {
        int xi;
        char ci;
        cin >> xi >> ci;

        s[xi - 1] = ci;
        results.push_back(f(s));
    }

    for (int res : results) {
        cout << res << endl;
    }

    return 0;
}