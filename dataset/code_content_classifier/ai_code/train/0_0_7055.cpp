#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int redSocks, blueSocks;
    cin >> redSocks >> blueSocks;

    int maxDays = min(redSocks, blueSocks);
    int sameSockDays = (max(redSocks, blueSocks) - maxDays) / 2;

    cout << maxDays << " " << sameSockDays << endl;

    return 0;
} 

// Example Input
// 3 1

// Example Output
// 1 1

// Example Input
// 2 3

// Example Output
// 2 0

// Example Input
// 7 3

// Example Output
// 3 2