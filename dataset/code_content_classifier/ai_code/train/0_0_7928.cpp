#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    bool performed_good = false;

    for (int i = 0; i < n; ++i) {
        string handle;
        int before, after;
        cin >> handle >> before >> after;

        if (before >= 2400 && after > before) {
            performed_good = true;
        }
    }

    if (performed_good) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}