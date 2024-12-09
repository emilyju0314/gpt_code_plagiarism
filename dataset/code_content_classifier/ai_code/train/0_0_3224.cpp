#include <iostream>
#include <vector>

using namespace std;

int ask(int i) {
    cout << "? " << i << endl;
    cout.flush();
    int val;
    cin >> val;
    return val;
}

int main() {
    int n;
    cin >> n;

    int left = 1, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        int val_mid = ask(mid);
        int val_mid_plus1 = ask(mid+1);

        if (val_mid < val_mid_plus1) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << "! " << left << endl;
    cout.flush();

    return 0;
}