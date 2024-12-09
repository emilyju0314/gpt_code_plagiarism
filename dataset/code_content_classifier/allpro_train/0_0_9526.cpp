#include <iostream>
#include <string>

using namespace std;

string minimizeDeletions(string S) {
    int A_count = 0;
    int Z_count = 0;
    
    for(char c : S) {
        if(c == 'A') {
            A_count++;
        } else {
            Z_count++;
        }
    }
    
    if(abs(A_count - Z_count) > 1) {
        return "-1";
    }
    
    string result = "";
    
    if(A_count > Z_count) {
        int A = 0;
        for(char c : S) {
            if(c == 'A') {
                result += c;
                A++;
                if(A == Z_count) {
                    break;
                }
            }
        }
    } else if(Z_count > A_count) {
        int Z = 0;
        for(char c : S) {
            if(c == 'Z') {
                result += c;
                Z++;
                if(Z == A_count) {
                    break;
                }
            }
        }
    } else {
        bool isA = true;
        for(char c : S) {
            if((isA && c == 'A') || (!isA && c == 'Z')) {
                result += c;
                isA = !isA;
            }
        }
    }
    
    return result;
}

int main() {
    string S;
    cin >> S;
    
    cout << minimizeDeletions(S) << endl;
    
    return 0;
}