#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    set<char> keys;
    string temp;
    for(int i = 0; i < k; i++) {
        char key;
        cin >> key;
        keys.insert(key);
    }

    long long count = 0;
    vector<int> freq(n+1, 0);

    for(int i = 1; i <= n; i++) {
        freq[i] = (keys.count(s[i-1]) > 0) ? freq[i-1] + 1 : 0;
        count += freq[i];
    }

    cout << count << endl;

    return 0;
}