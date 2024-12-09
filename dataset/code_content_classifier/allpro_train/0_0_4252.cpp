#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, h;
    cin >> n >> h;

    vector<int> bottles(n);
    for(int i = 0; i < n; i++) {
        cin >> bottles[i];
    }

    int total_height = 0;
    int max_k = 0;
    for(int k = 0; k < n; k++) {
        total_height = 0;
        for(int i = 0; i <= k; i += 2) {
            total_height += bottles[i];
        }

        if(total_height <= h) {
            max_k = k + 1;
        }
    }

    cout << max_k << endl;

    return 0;
}