#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int operations = 0;
    int count = 1;
    int current = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] == current) {
            count++;
        } else {
            operations += count;
            count = 1;
            current = arr[i];
        }
    }

    operations += count;

    cout << operations << endl;

    return 0;
}