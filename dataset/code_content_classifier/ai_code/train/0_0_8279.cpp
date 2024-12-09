#include <iostream>
#include <string>

using namespace std;

string minSubsequence(string a, string b) {
    int i = 0, j = 0;
    string result = "";
    
    while (i < a.length() && j < b.length()) {
        if (a[i] == b[j]) {
            result += b[j];
            j++;
        }
        i++;
    }
    
    if (result == "") {
        return "-";
    }
    
    return result;
}

int main() {
    string a, b;
    cin >> a >> b;
    
    string result = minSubsequence(a, b);
    cout << result << endl;
    
    return 0;
}