#include <iostream>
#include <string>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long l = 1, r = n;
    while (true) {
        long long mid = (l + r) / 2;
        cout << l << " " << mid << endl;
        string response1;
        cin >> response1;
        if (response1 == "Yes") {
            l = max(1LL, l - k);
            r = min(n, mid + k);
        } else if (response1 == "No") {
            if (r - l <= 1) {
                cout << l << " " << r << endl;
                break;
            }
            l = mid + 1;
        }

        cout << l << " " << r << endl;
        string response2;
        cin >> response2;
        if (response2 == "Yes") {
            l = max(1LL, l - k);
            r = min(r, mid + k);
        } else if (response2 == "No") {
            if (r - l <= 1) {
                cout << l << " " << r << endl;
                break;
            }
            r = mid;
        }
    }

    return 0;
}