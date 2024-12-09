#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canReachRise(int max, const vector<int>& instructions) {
    vector<bool> canReach(max+1, false);
    canReach[0] = true;
    
    for(int i = 0; i < max; i++) {
        if(canReach[i]) {
            for(int j = 0; j < instructions.size(); j++) {
                int newPos = i + instructions[j];
                if(newPos < 0) newPos = 0;
                if(newPos > max) newPos = max;
                
                canReach[newPos] = true;
            }
        }
    }
    
    return canReach[max];
}

int main() {
    int max;
    while(cin >> max && max > 0) {
        int n;
        cin >> n;
        
        vector<int> instructions;
        for(int i = 0; i < n; i++) {
            int instruction;
            cin >> instruction;
            instructions.push_back(instruction);
        }
        
        if(canReachRise(max, instructions)) {
            cout << "OK" << endl;
        } else {
            cout << "NG" << endl;
        }
    }
    
    return 0;
}