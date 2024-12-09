#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_erase = 0;
    for(int i = 0; i < n; i++) {
        int start = i;
        while(i+1 < n && arr[i+1] - arr[i] == 1) {
            i++;
        }
        max_erase = max(max_erase, i - start);
    }

    cout << max_erase << endl;

    return 0;
}