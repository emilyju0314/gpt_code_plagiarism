#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s = "";
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            s += "1";
        }
        else {
            s += "0";
        }
    }

    cout << s << endl;

    return 0;
}