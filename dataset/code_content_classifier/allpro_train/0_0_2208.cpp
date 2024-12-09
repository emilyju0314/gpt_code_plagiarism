#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dSorting(string& str, int k, int d) {
    for (int i = 0; i <= str.length() - k; ++i) {
        string sub = str.substr(i, k);
        for (int j = 0; j < k; ++j) {
            if (j % d == 0) {
                vector<char> tmp;
                for (int l = j; l < sub.length(); l += d) {
                    tmp.push_back(sub[l]);
                }
                sort(tmp.begin(), tmp.end());
                int index = 0;
                for (int l = j; l < sub.length(); l += d) {
                    sub[l] = tmp[index++];
                }
            }
        }
        str.replace(i, k, sub);
    }
}

int main() {
    string S;
    int m, n, k, d;
    
    cin >> S;
    cin >> m;
    
    for (int i = 0; i < m; ++i) {
        cin >> k >> d;
        dSorting(S, k, d);
        cout << S << endl;
    }
    
    return 0;
}