#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> numbers(n);
    unordered_map<long long, int> frequency;

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        frequency[numbers[i]]++;
    }

    sort(numbers.begin(), numbers.end());

    int half = n / 2;

    for (int i = 0; i < n; i++) {
        if (frequency[numbers[i]] >= half) {
            cout << numbers[i] << endl;
            break;
        }
    }

    return 0;
}