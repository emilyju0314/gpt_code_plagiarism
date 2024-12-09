#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, long long> memo;

long long countPatterns(int l, int k, bool topDark, bool bottomDark, int remaining) {
    if (remaining == 0) {
        return 1;
    }

    string key = to_string(topDark) + to_string(bottomDark) + to_string(remaining);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    long long result = 0;
    if (topDark) {
        if (bottomDark) {
            result += countPatterns(l, k, true, false, remaining-2);
            result += countPatterns(l, k, false, true, remaining-2);
        } else {
            result += countPatterns(l, k, true, true, remaining-2);
        }
    } else {
        result += countPatterns(l, k, true, false, remaining-1);
    }

    if (remaining >= k) {
        result += countPatterns(l, k, false, false, remaining-k);
    }

    memo[key] = result;
    return result;
}

int main() {
    int l, k;
    cin >> l >> k;

    long long result = countPatterns(l, k, true, true, l);
    cout << result << endl;

    return 0;
}