#include <iostream>
#include <string>

using namespace std;

int countSubstrings(string t, string sbegin, string send) {
    int count = 0;
    size_t beginPos = 0;
    
    while ((beginPos = t.find(sbegin, beginPos)) != string::npos) {
        size_t endPos = beginPos + sbegin.size();
        size_t endSearchPos = endPos + 1;
        
        while ((endSearchPos = t.find(send, endSearchPos)) != string::npos) {
            count++;
            endPos = endSearchPos + send.size();
            endSearchPos++;
        }
        
        beginPos++;
    }
    
    return count;
}

int main() {
    string t, sbegin, send;
    cin >> t >> sbegin >> send;
    
    int result = countSubstrings(t, sbegin, send);
    
    cout << result << endl;
    
    return 0;
}