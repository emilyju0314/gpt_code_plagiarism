#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    int count = 0;
    long long prod = 1;
    int right = 0;
    for (int left = 0; left < n; left++) {
        while (right < n && prod * cards[right] % k != 0) {
            prod *= cards[right];
            right++;
        }
        count += n - right;

        if (left == right) {
            right++;
        } else {
            prod /= cards[left];
        }
    }

    cout << count << endl;

    return 0;
}