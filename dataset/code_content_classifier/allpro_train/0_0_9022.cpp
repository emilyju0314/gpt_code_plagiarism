#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> sequence(n);
    
    for(int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    
    vector<vector<string>> program(n, vector<string>(2));
    
    int penalty = 0;
    
    for(int i = 0; i < n; i++) {
        string variable = "abcdefghijklmnopqrstuvwxyz"[i % m];
        string operation;
        if(i == 0) {
            operation = variable + "=" + to_string(sequence[i]);
            penalty += bitset<32>(sequence[i]).count();
        } else {
            operation = "print(" + variable + ")";
        }
        
        program[i][0] = operation;
        program[i][1] = variable;
    }
    
    cout << n << " " << penalty << endl;
    
    for(int i = 0; i < n; i++) {
        cout << program[i][0] << endl;
    }
    
    return 0;
}