#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int pyramids = 0;
        int height = 0;
        
        while (n >= height + 2) {
            height++;
            pyramids++;
            n -= height;
        }

        cout << pyramids << endl;
    }

    return 0;
}