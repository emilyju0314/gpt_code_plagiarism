#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve(vector<int>& A, int N, vector<int>& order, int start, int end) {
    if (start == end) {
        if (A[start - 1] == order[start])
            return true;
        else
            return false;
    }

    vector<int> next_half;
    for (int i = start; i <= end; i++) {
        next_half.push_back(order[i]);
    }

    vector<int> lost_order, won_order;
    for (int i = 0; i < next_half.size(); i += 2) {
        if (next_half[i] > next_half[i + 1]) {
            lost_order.push_back(next_half[i]);
            won_order.push_back(next_half[i + 1]);
        } else {
            lost_order.push_back(next_half[i + 1]);
            won_order.push_back(next_half[i]);
        }
    }

    int next_start = start;
    for (int i = 0; i < won_order.size(); i++) {
        order[next_start] = won_order[i];
        next_start++;
    }

    if (solve(A, N-1, order, start, next_start-1))
        return true;

    int next_end = start + (1 << N-1) - 1;
    for (int i = 0; i < lost_order.size(); i++) {
        order[next_end] = lost_order[i];
        next_end++;
    }

    if (solve(A, N-1, order, next_start, next_end-1))
        return true;

    return false;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(1 << N);
    for (int i = 1; i <= (1 << N); i++) {
        cin >> A[i];
    }

    vector<int> order(1 << N);
    if (solve(A, N, order, 1, 1 << N)) {
        cout << "YES" << endl;
        for (int i = 1; i <= (1 << N); i++) {
            cout << order[i] << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}