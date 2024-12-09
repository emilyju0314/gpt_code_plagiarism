#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int beauty = -1;
    int max_num = numbers[n-1];
    while (max_num % 2 == 0) {
        max_num /= 2;
    }

    cout << "1" << endl;
    cout << max_num << endl;

    return 0;
}