#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int BASE = 31;

int add(int a, int b) {
    return (a + b) % MOD;
}

int multiply(int a, int b) {
    return (1LL * a * b) % MOD;
}

int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = multiply(res, a);
        }
        a = multiply(a, a);
        b /= 2;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    unordered_set<string> words;
    vector<string> allWords;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.insert(word);
        allWords.push_back(word);
    }

    int cnt = 1;
    for (int i = 0; i < 12; i++) {
        unordered_set<int> hashes;
        for (string word : allWords) {
            int hash = 0;
            for (char c : word) {
                hash = add(multiply(hash, BASE), c - 'a' + 1);
            }
            hashes.insert(hash);
        }
        cnt = multiply(cnt, hashes.size());
    }

    cout << cnt << endl;

    return 0;
}