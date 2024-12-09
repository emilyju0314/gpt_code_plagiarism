#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    long long result = 1;
    bool overflow = false;
    for (int i = 0; i < N; i++) {
        if (numbers[i] == 0) {
            result = 0;
            break;
        }
        if (result > 1000000000000000000 / numbers[i]) {
            overflow = true;
            break;
        }
        result *= numbers[i];
    }

    if (overflow) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
}