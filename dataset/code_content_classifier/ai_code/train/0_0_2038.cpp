#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int al, ar, bl, br;
    cin >> al >> ar >> bl >> br;

    int maxGirlFingers = max(al, ar);
    int minGirlFingers = min(al, ar);
    int maxBoyFingers = max(bl, br);
    int minBoyFingers = min(bl, br);

    if ((maxGirlFingers <= maxBoyFingers && minGirlFingers <= minBoyFingers) || (maxGirlFingers <= minBoyFingers && minGirlFingers <= maxBoyFingers)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}