#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < Q; i++) {
        int query;
        cin >> query;

        if(query == 1) {
            int l, r;
            cin >> l >> r;
            int sum = 0;
            for(int j = l; j < r; j++) {
                sum += arr[j];
            }
            cout << sum << endl;
        } else {
            int p, x;
            cin >> p >> x;
            arr[p] += x;
        }
    }

    return 0;
}