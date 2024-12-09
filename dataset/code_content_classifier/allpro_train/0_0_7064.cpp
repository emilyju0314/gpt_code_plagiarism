#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int l = 1, r = n, mid;
    string response;

    while (l < r) {
        mid = (l + r) / 2;
        cout << "1 " << l << " " << mid << endl;
        cout.flush();
        cin >> response;

        if (response == "TAK") {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << "1 " << l << " " << r << endl;
    cout.flush();
    cin >> response;

    if (response == "TAK") {
        cout << "2 " << l << " " << r << endl;
    } else {
        cout << "2 " << r << " " << l << endl;
    }

    cout.flush();

    return 0;
}