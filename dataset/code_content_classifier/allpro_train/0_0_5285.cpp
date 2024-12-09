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
        string response;
        cin >> response;
        if (response == "Yes") {
            r = mid;
            if (l == r) {
                break;
            }
        } else {
            l = mid + 1;
            if (l > r) {
                break;
            }
        }
    }

    return 0;
}