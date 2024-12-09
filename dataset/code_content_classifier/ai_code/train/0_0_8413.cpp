#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> numbers(n);
    for(int i=0; i<n; i++) {
        cin >> numbers[i];
    }

    long long minNum = *min_element(numbers.begin(), numbers.end());
    long long operations = 0;
    for(int i=0; i<n; i++) {
        operations += (numbers[i] - minNum) / 2;
    }

    cout << operations << endl;

    return 0;
}