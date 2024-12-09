#include <iostream>
#include <string>

using namespace std;

long long solve(long long l, long long r) {
    string s = to_string(r);
    long long ans = 0;
    for (char c : s) {
        ans += c - '0';
    }
    return ans;
}

int main() {
    long long a;
    cin >> a;

    long long l = 1;
    long long r = a + 1;

    cout << l << " " << r << endl;

    return 0;
}