#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    if (a.size() != b.size()) {
        cout << "NO" << endl;
        return 0;
    }

    bool canTransform = true;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i] && !(a[i] == '1' && b[i] == '0')) {
            canTransform = false;
            break;
        }
    }

    if (canTransform) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}