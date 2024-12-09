#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    int max_sweets = -1;
    for(int i = 0; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;

        if(xi < s || (xi == s && yi == 0)) {
            int remaining_cents = 100 - yi;
            if(remaining_cents > 0) {
                max_sweets = max(max_sweets, remaining_cents);
            }
        }
    }

    cout << max_sweets << endl;

    return 0;
}