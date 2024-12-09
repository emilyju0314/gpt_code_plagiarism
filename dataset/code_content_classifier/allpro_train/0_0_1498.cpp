#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    string symbols;
    cin >> symbols;

    sort(numbers.begin(), numbers.end());

    string result;
    for (int i = 0; i < n; i++) {
        result += to_string(numbers[i]);
        if (i != n - 1) {
            result += symbols[i];
        }
    }

    cout << result << endl;

    return 0;
}