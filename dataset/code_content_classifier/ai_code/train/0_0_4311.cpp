#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long R, B;
    cin >> R >> B;

    long long K = min(R, B) + 1; // Initialize K with the minimum of R and B + 1

    while (true) {
        // Calculate the number of red balls in each box
        long long red_per_box = (R - (K - 1)) / (K - 1);
        if (red_per_box <= 0) {
            break;
        }

        // Calculate the number of blue balls in each box
        long long blue_per_box = (B - (K - 1)) / (K - 1);

        // Check if the number of blue balls is enough to distribute in all boxes
        if (red_per_box + blue_per_box < 1) {
            break;
        }

        // Update K if possible
        K++;
    }

    cout << K << endl;

    return 0;
}