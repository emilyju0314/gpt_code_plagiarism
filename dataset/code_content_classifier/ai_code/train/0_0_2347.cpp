#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> colors(n);
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    int max_length = 1;
    int curr_length = 1;
    for (int i = 1; i < n; i++) {
        if (colors[i] != colors[i - 1]) {
            curr_length++;
        } else {
            max_length = max(max_length, curr_length);
            curr_length = 1;
        }
    }

    max_length = max(max_length, curr_length);

    cout << max_length << endl;

    return 0;
}