#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    long long neg_count = 0, zero_count = 0, pos_count = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] < 0) {
            neg_count++;
        } else if (A[i] == 0) {
            zero_count++;
        } else {
            pos_count++;
        }
    }

    auto get_pairs = [&](int x) {
        if (x < 0) {
            return neg_count;
        } else if (x == 0) {
            return neg_count + zero_count;
        } else {
            return N - pos_count;
        }
    };

    long long left = -1e18, right = 1e18;

    while (right - left > 1) {
        long long mid = (left + right) / 2;
        long long count = 0;

        for (int i = 0; i < N; i++) {
            if (A[i] < 0) {
                count += get_pairs(A[i] * mid);
            } else {
                auto it = upper_bound(A.begin(), A.end(), 0);
                if (A[i] != 0) {
                    it = upper_bound(A.begin(), A.end(), mid / A[i]);
                }

                count += A.end() - it;
                if (A[i]*A[i] <= mid) {
                    count--;
                }

                if (A[i] > 0) {
                    count -= N - pos_count;
                }
            }
        }

        count /= 2;

        if (count < K) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left << endl;

    return 0;
}