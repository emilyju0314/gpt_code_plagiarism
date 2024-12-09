#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

string generateBAString(int n, int k, long long x, string s) {
    vector<int> asteriskIndices;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            asteriskIndices.push_back(i);
        }
    }

    string result = "";
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            result += 'a';
        } else {
            long long count = min(x, (long long) k);
            x -= count;
            for (int j = 0; j < count; j++) {
                result += 'b';
            }
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        long long x;
        string s;
        cin >> n >> k >> x;
        cin >> s;

        string baString = generateBAString(n, k, x, s);
        cout << baString << endl;
    }

    return 0;
}