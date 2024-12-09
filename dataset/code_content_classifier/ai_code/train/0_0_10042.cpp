#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers;
    int num;

    for (int i = 0; i < 6; i++) {
        cin >> num;
        numbers.push_back(num);
    }

    // Sort the numbers
    sort(numbers.begin(), numbers.end());

    // Find the second largest number
    cout << numbers[numbers.size()-2] << endl;

    return 0;
}