#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string errtype = "errtype";
unordered_map<string, string> typedefs;

string typeof(string t) {
    while (t[0] == '&') {
        t = t.substr(1);
    }
    return typedefs.count(t) ? typedefs[t] : errtype;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string op, a, b;
        cin >> op;
        if (op == "typedef") {
            cin >> a >> b;
            typedefs[b] = a;
        } else if (op == "typeof") {
            cin >> a;
            cout << typeof(a) << endl;
        }
    }

    return 0;
}