#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> pixels(n);
    for(int i = 0; i < n; i++) {
        cin >> pixels[i];
    }

    vector<int> group_key(256, 0);
    int current_key = 0;
    for(int i = 0; i < 256; i += k) {
        for(int j = i; j < min(i + k, 256); j++) {
            group_key[j] = current_key;
        }
        current_key = min(current_key + k, 256);
    }

    for(int i = 0; i < n; i++) {
        cout << group_key[pixels[i]] << " ";
    }

    return 0;
}