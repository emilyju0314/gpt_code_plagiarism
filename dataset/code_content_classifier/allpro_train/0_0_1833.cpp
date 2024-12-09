#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int s;
        cin >> s;

        int total_spent = 0;
        while(s >= 10) {
            int spent = s - s/10;
            total_spent += spent;
            s = s/10 + s%10;
        }

        total_spent += s;
        cout << total_spent << endl;
    }

    return 0;
}