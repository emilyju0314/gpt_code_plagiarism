#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double calculateProbability(string s1, string s2) {
    int n = s1.size();
    
    int finalPos = 0; // final position according to s1
    int pos = 0; // current position after following recognized commands
    
    int unrecognized_count = 0;
    int correct_count = 0;
    
    for (int i = 0; i < n; i++) {
        if (s1[i] == '+') {
            finalPos++;
        } else {
            finalPos--;
        }
        
        if (s2[i] == '+') {
            pos++;
        } else if (s2[i] == '-') {
            pos--;
        } else {
            unrecognized_count++;
        }
    }
    
    for (int mask = 0; mask < (1 << unrecognized_count); mask++) {
        int tempPos = pos;
        int bit = 0;
        for (int i = 0; i < n; i++) {
            if (s2[i] == '?' && (mask & (1 << bit))) {
                tempPos++;
            } else if (s2[i] == '?' && !(mask & (1 << bit))) {
                tempPos--;
            }
            
            bit++;
        }
        
        if (tempPos == finalPos) {
            correct_count++;
        }
    }
    
    return (double)correct_count / pow(2, unrecognized_count);
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    double probability = calculateProbability(s1, s2);
    
    cout << fixed;
    cout.precision(12);
    cout << probability << endl;
    
    return 0;
}