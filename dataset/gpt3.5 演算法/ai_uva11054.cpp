#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, caseNum = 1;
    while (cin >> n) {
        vector<int> numbers(n);
        for (int i = 0; i < n; ++i) {
            cin >> numbers[i];
        }

        long long maxProduct = 0;
        for (int i = 0; i < n; ++i) {
            long long product = 1;
            for (int j = i; j < n; ++j) {
                product *= numbers[j];
                maxProduct = max(maxProduct, product);
            }
        }

        cout << "Case #" << caseNum++ << ": The maximum product is " << maxProduct << ".\n\n";
    }

    return 0;
}
