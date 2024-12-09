#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    int odd_count = 0;
    for (int i = 0; i < N; i++) {
        if (numbers[i] % 2 != 0) {
            odd_count++;
        }
    }

    if (odd_count % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}