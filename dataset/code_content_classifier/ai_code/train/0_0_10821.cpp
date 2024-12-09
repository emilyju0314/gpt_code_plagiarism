#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n, T;
    cin >> n >> T;
    
    string polynomial;
    cin.ignore();
    getline(cin, polynomial);
    
    long long totalExecutionTime = 0;
    long long factor = 1;
    
    for(int i = 0; i < polynomial.size(); i++) {
        if(polynomial[i] == 'n' && polynomial[i+2] == '^') {
            int power = polynomial[i+4] - '0';
            totalExecutionTime += pow(n, power) * factor;
            i += 4;
        } else if(polynomial[i] == '+') {
            continue;
        } else {
            factor = T;
        }
    }
    
    if(totalExecutionTime <= 1000000000) {
        cout << totalExecutionTime << endl;
    } else {
        cout << "TLE" << endl;
    }
    
    return 0;
}