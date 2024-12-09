#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int getResult(string s, int l, int r) {
    int n = r - l + 1;
    unordered_map<string, int> freq;
    for(int i = l-1; i < r; i++) {
        string segment = "";
        for(int j = i; j < r; j++) {
            segment += s[j];
            freq[segment]++;
        }
    }

    for(auto it = freq.begin(); it != freq.end(); it++) {
        if(it->second >= 2) {
            return it->first.length();
        }
    }

    return -1;
}

int main() {
    int n, q;
    string band;
    cin >> n >> band;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << getResult(band, l, r) << endl;
    }

    return 0;
}