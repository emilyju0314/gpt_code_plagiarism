#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isKBalanced(string s, int k) {
    int n = s.length();
    vector<int> zeroCount(n + 1), oneCount(n + 1);

    for(int i = 1; i <= n; i++) {
        zeroCount[i] = zeroCount[i-1] + (s[i-1] == '0' || s[i-1] == '?');
        oneCount[i] = oneCount[i-1] + (s[i-1] == '1' || s[i-1] == '?');
    }

    for(int i = k; i <= n; i++) {
        int zeros = zeroCount[i] - zeroCount[i-k];
        int ones = oneCount[i] - oneCount[i-k];
        int unknowns = k - zeros - ones;

        if(zeros + unknowns/2 >= ones && ones + unknowns/2 >= zeros) {
            return true;
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        if(isKBalanced(s, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}