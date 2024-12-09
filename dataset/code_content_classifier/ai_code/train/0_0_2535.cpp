#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int a, b;
        cin >> a >> b;

        // Find the common prefix of a and b
        int x = 0;
        for(int i = 30; i >= 0; i--) {
            if((a & (1 << i)) != (b & (1 << i))) {
                x = (1 << (i + 1)) - 1;
                break;
            }
        }

        cout << (a^x) + (b^x) << endl;
    }

    return 0;
}