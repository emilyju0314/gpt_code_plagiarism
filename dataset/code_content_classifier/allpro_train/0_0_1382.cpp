#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    int count = 0;
    
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i]) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}