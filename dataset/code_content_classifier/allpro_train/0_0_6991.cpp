#include <iostream>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;

        // calculate the maximum possible number of participants whose scores are smaller than Takahashi's
        long long result = (long long)A * B - A - B + 1;
        cout << result << endl;
    }

    return 0;
}