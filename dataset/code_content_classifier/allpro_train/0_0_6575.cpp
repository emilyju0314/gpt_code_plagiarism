#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int left = 1, right = N, answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (mid % 2 == 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}