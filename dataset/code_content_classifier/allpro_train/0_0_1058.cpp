#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(int x, int y) {
    return (x | y) - y;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), [](int a, int b) {
        return a > b;
    });

    vector<int> result;
    for(int i = 0; i < n; i++) {
        result.push_back(arr[i]);
    }

    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}