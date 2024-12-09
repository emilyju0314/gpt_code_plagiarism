#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> requests(n);
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
    }
    
    int additionalRequests = 0;
    
    // Count the number of additional requests needed for increasing part
    int increasingPart = 0;
    int prev = requests[0];
    for (int i = 1; i < n; i++) {
        if (requests[i] > prev) {
            prev = requests[i];
        } else {
            int diff = prev - requests[i] + 1;
            prev += diff;
            increasingPart += diff;
        }
    }
    
    prev = requests[n-1];
    // Count the number of additional requests needed for decreasing part
    int decreasingPart = 0;
    for (int i = n-2; i >= 0; i--) {
        if (requests[i] > prev) {
            prev = requests[i];
        } else {
            int diff = prev - requests[i] + 1;
            prev += diff;
            decreasingPart += diff;
        }
    }
    
    additionalRequests = max(increasingPart, decreasingPart);
    
    cout << additionalRequests << endl;
    
    return 0;
}