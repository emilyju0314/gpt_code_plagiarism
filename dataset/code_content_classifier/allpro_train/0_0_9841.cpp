#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool isGoodMessage(string message) {
    int n = message.length();
    unordered_set<string> shifts;
    
    for (int i = 0; i < n; i++) {
        shifts.insert(message.substr(i) + message.substr(0, i));
    }
    
    return shifts.size() == n; // check if all cyclic shifts are distinct
}

int main() {
    int n;
    cin >> n;
    
    vector<string> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    int total = 0;
    
    for (int start = 0; start < n; start++) {
        for (int end = start; end < n; end++) {
            vector<string> sublist(A.begin() + start, A.begin() + end + 1);
            string concat;
            for (string s : sublist) {
                concat += s;
            }
            if (isGoodMessage(concat)) {
                total++;
            }
        }
    }
    
    cout << total << endl;
    
    return 0;
}