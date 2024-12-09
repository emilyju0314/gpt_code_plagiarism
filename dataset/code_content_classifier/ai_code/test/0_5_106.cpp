#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        arr[0] = 1;
        for(int i = 1; i < n; i++) {
            arr[i] = arr[i-1] * 10 + 1;
        }

        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}