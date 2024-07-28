#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> numbers(n);
        for (int i = 0; i < n; ++i) {
            cin >> numbers[i];
        }

        sort(numbers.begin(), numbers.end());

        int sum = 0;
        for (int i = 1; i < n - 1; ++i) {
            sum += numbers[i];
        }

        int average = sum / (n - 2);
        int result = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (numbers[i] < average) {
                result += average - numbers[i];
            }
        }

        cout << result << endl;
    }

    return 0;
}
