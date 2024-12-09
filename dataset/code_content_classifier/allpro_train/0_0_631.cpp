#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int diff = abs(n - m);
    string result = "";

    if (n > m) {
        result += "B";
        n--;
    } else {
        result += "G";
        m--;
    }

    for (int i = 0; i < diff; i++) {
        if (n > 0) {
            result += "B";
            n--;
        } else {
            result += "G";
            m--;
        }
        result += (i % 2 == 0) ? "G" : "B";
    }

    for (int i = 0; i < min(n, m); i++) {
        result += "BG";
    }

    cout << result << endl;

    return 0;
}