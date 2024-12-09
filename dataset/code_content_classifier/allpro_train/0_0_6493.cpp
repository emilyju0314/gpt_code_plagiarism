#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;

    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    deque<int> dq;

    for (int i = 0; i < N; i++) {
        while (!dq.empty() && dq.front() < i - L + 1) {
            dq.pop_front();
        }

        while (!dq.empty() && arr[i] < arr[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= L - 1) {
            cout << arr[dq.front()] << " ";
        }
    }

    return 0;
}