#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> increasing_forward(n, 1);
    vector<int> increasing_backward(n, 1);

    for(int i = 1; i < n; i++) {
        if(a[i] > a[i-1]) {
            increasing_forward[i] = increasing_forward[i-1] + 1;
        }
    }

    for(int i = n-2; i >= 0; i--) {
        if(a[i] < a[i+1]) {
            increasing_backward[i] = increasing_backward[i+1] + 1;
        }
    }

    int best_length = 0;
    for(int i = 0; i < n; i++) {
        int current_length = 1;
        if(i > 0) {
            current_length += increasing_forward[i-1];
        }
        if(i < n-1) {
            current_length += increasing_backward[i+1];
        }
        best_length = max(best_length, current_length);
    }

    cout << best_length << endl;

    return 0;
}