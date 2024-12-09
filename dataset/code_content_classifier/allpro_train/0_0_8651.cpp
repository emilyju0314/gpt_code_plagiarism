#include <iostream>
#include <map>
#include <vector>

using namespace std;

pair<int, int> calculateRecurringPart(int x, int y) {
    map<int, int> remainderIdx;
    vector<int> decimals;
    
    int quotient = x / y;
    int remainder = x % y;
    int recurringStart = -1;
    int recurringLength = 0;
    
    while (remainder != 0 && remainderIdx.find(remainder) == remainderIdx.end()) {
        remainderIdx[remainder] = decimals.size();
        decimals.push_back(remainder * 10 / y);
        remainder = (remainder * 10) % y;
    }
    
    if (remainder != 0) {
        recurringStart = remainderIdx[remainder];
        recurringLength = decimals.size() - recurringStart;
    }
    
    return {recurringStart, recurringLength};
}

int main() {
    int x, y;
    
    while (cin >> x >> y) {
        if (x == 0 && y == 0) {
            break;
        }
        
        pair<int, int> result = calculateRecurringPart(x, y);
        cout << result.first << " " << result.second << endl;
    }
    
    return 0;
}