#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int count = 0;
    long long sum = 0;

    for (int i = 0; i < N; i++) {
        sum = 0;
        for (int j = i; j < N; j++) {
            sum += arr[j];
            int len = j - i + 1;
            if (sum >= (long long) K * len) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}