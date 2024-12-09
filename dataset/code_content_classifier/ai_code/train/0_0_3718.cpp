#include <iostream>
#include <string>

using namespace std;

int compressString(string s) {
    int n = s.length();
    
    string compressed;
    for(int i = 0; i < n; i++) {
        if(i < n-1 && isalpha(s[i]) && isalpha(s[i+1])) {
            int j = i;
            while(j < n && isalpha(s[j])) {
                j++;
            }
            compressed += s[i];
            compressed += '-';
            compressed += s[j-1];
            i = j-1;
        } else if(i < n-1 && isdigit(s[i]) && isdigit(s[i+1])) {
            int j = i;
            while(j < n && isdigit(s[j])) {
                j++;
            }
            compressed += s[i];
            compressed += '-';
            compressed += s[j-1];
            i = j-1;
        } else {
            compressed += s[i];
        }
    }
    
    if(compressed.length() < n) {
        return compressString(compressed);
    } else {
        return n;
    }
}

int main() {
    string s;
    cin >> s;
    
    int result = compressString(s);
    cout << result << endl;
    
    return 0;
}