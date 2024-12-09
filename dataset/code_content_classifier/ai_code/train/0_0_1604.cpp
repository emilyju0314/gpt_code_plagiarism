#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int n, k;
vector<string> requirements;
int count = 0;

bool isValidSequence(vector<int>& sequence) {
    for (int i = 0; i <= n; i++) {
        if (sequence[i] > sequence[2*n-i-1]) {
            return false;
        }
    }
    for (int i = 0; i < k; i++) {
        int xi = requirements[i][0] - '0';
        int yi = requirements[i][2] - '0';
        char sign = requirements[i][1];
        
        if (sign == '=') {
            if (sequence[xi-1] != sequence[yi-1]) return false;
        } else if (sign == '<') {
            if (sequence[xi-1] >= sequence[yi-1]) return false;
        } else if (sign == '>') {
            if (sequence[xi-1] <= sequence[yi-1]) return false;
        } else if (sign == '<=') {
            if (sequence[xi-1] > sequence[yi-1]) return false;
        } else if (sign == '>=') {
            if (sequence[xi-1] < sequence[yi-1]) return false;
        }
    }
    return true;
}

void generateSequences(vector<int>& sequence, int index) {
    if (index == 2*n) {
        if (isValidSequence(sequence)) {
            count++;
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        sequence[index] = i;
        generateSequences(sequence, index+1);
    }
}

int main() {
    cin >> n >> k;
    
    requirements.resize(k);
    
    for (int i = 0; i < k; i++) {
        cin >> requirements[i];
    }
    
    vector<int> sequence(2*n);
    
    generateSequences(sequence, 0);
    
    cout << count << endl;
    
    return 0;
}