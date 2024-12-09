#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int area = (c - a + 1) * (d - b + 1);
        
        int black_stones = (d - b + 1) / 2 * (c - a + 1);
        int white_stones = (d - b + 1) * (c - a + 1) - black_stones;

        int max_stones = min(black_stones, white_stones) * 2;

        cout << max_stones << endl;
    }

    return 0;
}