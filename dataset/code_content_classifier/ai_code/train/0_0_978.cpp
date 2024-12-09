#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        int remaining_sum = n * (n + 1) / 2 - k;

        vector<int> chosen_numbers;
        for (int i = 1; i <= n; ++i) {
            if (i != remaining_sum) {
                chosen_numbers.push_back(i);
            }
        }

        cout << chosen_numbers.size() << endl;
        for (int num : chosen_numbers) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}