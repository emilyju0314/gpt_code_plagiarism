#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        // Counting the number of Pythagorean triples (a, b, c) that satisfy both conditions
        int count = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = a; b <= n; b++) {
                int c = a * a + b;
                if (c <= n && c >= b && c * c == a * a + b * b) {
                    count++;
                }
            }
        }

        cout << count << endl;
    }
    
    return 0;
}