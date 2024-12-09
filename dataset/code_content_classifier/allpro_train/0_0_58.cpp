#include <iostream>
#include <string>

using namespace std;

void generateStrings(int N, string s) {
    if (s.length() == N) {
        cout << s << endl;
        return;
    }
    char start = 'a';
    if (!s.empty() && s.back() == start) start++;
    for (char c = start; c <= 'z'; c++) {
        generateStrings(N, s + c);
    }
}

int main() {
    int N;
    cin >> N;

    generateStrings(N, "");
    
    return 0;
}