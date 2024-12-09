#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int max_sum_of_squares = 0;
    int max_element = *max_element(numbers.begin(), numbers.end());

    int max_bit = log2(max_element);
    int total_bits = max_bit + 1;

    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += numbers[i] * numbers[i];
    }

    cout << sum + 2LL * total_bits * accumulate(numbers.begin(), numbers.end(), 0LL) << endl;
   
    return 0;
}