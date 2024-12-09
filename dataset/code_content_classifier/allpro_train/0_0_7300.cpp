#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countDistinctIntegers(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int count = 0;
    for(int i = 0; i < b.size() - a.size() + 1; i++) {
        bool isSubsequence = true;
        for(int j = 0; j < a.size(); j++) {
            if(a[j] != b[i+j]) {
                isSubsequence = false;
                break;
            }
        }
        if(isSubsequence) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int answer = countDistinctIntegers(a, b);
    cout << answer << endl;

    return 0;
}