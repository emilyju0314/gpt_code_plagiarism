#include<iostream>
#include<string>

using namespace std;

int main() {
    string T, P;
    cin >> T >> P;
    
    int t_idx = 0, p_idx = 0;
    
    while (t_idx < T.length() && p_idx < P.length()) {
        if (T[t_idx] == P[p_idx]) {
            p_idx++;
        }
        t_idx++;
    }
    
    if (p_idx == P.length()) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    
    return 0;
}