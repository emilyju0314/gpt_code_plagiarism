#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> sums(n);
    for(int i = 0; i < n; i++) {
        cin >> sums[i];
    }

    for(int i = 0; i < n; i++) {
        int num = 0;
        while(sums[i] > 0) {
            num = num*10 + min(sums[i], 9);
            sums[i] -= min(sums[i], 9);
        }
        cout << num << endl;
    }

    return 0;
}