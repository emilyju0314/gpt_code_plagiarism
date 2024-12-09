#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> xorCount;
    xorCount[0] = 1;

    int xorResult = 0;
    long long count = 0;

    for(int i = 0; i < n; i++) {
        xorResult ^= a[i];
        if(i % 2 == 1) {
            count += xorCount[xorResult];
        }
        xorCount[xorResult]++;
    }

    cout << count << endl;

    return 0;
}