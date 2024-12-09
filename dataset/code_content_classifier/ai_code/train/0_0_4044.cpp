#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

bool isRegularBracketSequence(string s) {
    stack<char> st;
    for(char c : s) {
        if(c == '(') {
            st.push(c);
        } else {
            if(st.empty()) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    int n;
    cin >> n;

    vector<string> sequences(n);
    vector<string> reversedSequences(n);

    int regularCount = 0;

    for(int i = 0; i < n; i++) {
        cin >> sequences[i];
        reversedSequences[i] = sequences[i];
        reverse(reversedSequences[i].begin(), reversedSequences[i].end());
        if(isRegularBracketSequence(sequences[i])) {
            regularCount++;
        }
    }

    map<string, int> countMap;

    for(string s : sequences) {
        countMap[s]++;
    }

    for(string s : reversedSequences) {
        countMap[s]++;
    }

    long long ans = 0;

    for(int i = 0; i < n; i++) {
        ans += countMap[sequences[i]];
    }

    cout << ans - regularCount * 2 << endl;

    return 0;
}