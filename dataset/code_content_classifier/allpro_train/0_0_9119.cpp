#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += 5;
    }

    int min_re_sit = 0;
    while (sum < k) {
        sum += 2;
        min_re_sit++;
    }

    cout << min_re_sit << endl;

    return 0;
}