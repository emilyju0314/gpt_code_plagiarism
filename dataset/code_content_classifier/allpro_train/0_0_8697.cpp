#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a < b) {
        cout << 0 << endl;
    } else if (a == b) {
        cout << "infinity" << endl;
        return 0;
    } else {
        int count = 0;
        for (int i = 1; i*i <= a-b; i++) {
            if ((a-b) % i == 0) {
                if (i > b) {
                    count++;
                }
                if (i*i != a-b && (a-b)/i > b) {
                    count++;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}