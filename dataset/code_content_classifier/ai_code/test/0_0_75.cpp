#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0, right = n - 1;
    int turn = 1; // 1 for Alice, -1 for Bob

    vector<int> seq;
    while(left <= right) {
        int choose = max(arr[left], arr[right]);
        if(arr[left] > arr[right]) left++;
        else right--;

        if(turn == 1) {
            seq.push_back(choose);
            turn = -1;
        } else {
            turn = 1;
        }
    }

    if(is_sorted(seq.begin(), seq.end())) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }

    return 0;
}