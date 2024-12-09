#include <iostream>
using namespace std;

int main() {
    long long l1, r1, l2, r2, k;
    cin >> l1 >> r1 >> l2 >> r2 >> k;

    long long overlappingStart = max(l1, l2);
    long long overlappingEnd = min(r1, r2);

    long long totalMinutes = overlappingEnd - overlappingStart + 1;
    
    if(overlappingStart <= k && k <= overlappingEnd) {
        totalMinutes--;
    }

    if(totalMinutes < 0) {
        totalMinutes = 0;
    }

    cout << totalMinutes << endl;

    return 0;
}