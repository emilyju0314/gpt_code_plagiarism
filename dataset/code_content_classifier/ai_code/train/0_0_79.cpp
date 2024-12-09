#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num % k == 0) {
            sum += num / k;
        } else {
            sum += (num / k) + 1;
        }
    }

    cout << sum << endl;

    return 0;
}