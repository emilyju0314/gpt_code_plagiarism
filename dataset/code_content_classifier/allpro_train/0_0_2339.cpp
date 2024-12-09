#include <iostream>
#include <string>
using namespace std;

int main() {
    string era;
    int y, m, d;

    while (true) {
        cin >> era;
        if (era == "#") {
            break;
        }

        cin >> y >> m >> d;

        if (era == "HEISEI" && y > 31) {
            cout << "? " << y-31 << " " << m << " " << d << endl;
        } else {
            cout << "HEISEI " << y << " " << m << " " << d << endl;
        }
    }

    return 0;
}