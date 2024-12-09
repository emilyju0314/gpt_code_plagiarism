#include <iostream>

using namespace std;

int main() {
    int n, count = 0;
    cin >> n;

    int total_cookies = 0;
    for (int i = 0; i < n; i++) {
        int cookies;
        cin >> cookies;
        total_cookies += cookies;
    }

    for (int i = 0; i < n; i++) {
        int cookies = total_cookies - ai[i];
        if (cookies % 2 == 0) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}