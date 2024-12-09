#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isBeautiful(int num) {
    string strNum = to_string(num);
    int countOnes = 0;
    for(char digit : strNum) {
        if(digit == '1') {
            countOnes++;
        }
        if(countOnes > 1) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> tanks(n);
    
    for(int i = 0; i < n; i++) {
        cin >> tanks[i];
    }
    
    long long product = 1;
    
    for(int i = 0; i < n; i++) {
        if(!isBeautiful(tanks[i])) {
            product = 0;
            break;
        }
        product *= tanks[i];
    }
    
    cout << product << endl;
    
    return 0;
}