#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateSets(int n, int k, int s) {
    if (k == 0 && s == 0) {
        return 1;
    }
    if (n == 0 || k == 0 || s == 0) {
        return 0;
    }
    if (k == 1) {
        return (s <= n) ? 1 : 0;
    }
    int res = 0;
    res += calculateSets(n-1, k-1, s-n);
    res += calculateSets(n-1, k, s);
    return res;
}

int main() {
    int n, k, s;
    while (cin >> n >> k >> s) {
        if (n == 0 && k == 0 && s == 0) {
            break;
        }
        int result = calculateSets(n, k, s);
        cout << result << endl;
    }
    return 0;
}