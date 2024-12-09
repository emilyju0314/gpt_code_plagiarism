#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> count(10, 0);
    
    for(int i = 0; i < n; i++) {
        char digit;
        cin >> digit;
        count[digit - '0']++;
    }
    
    int numOfPhoneNumbers = INT_MAX;
    
    // Calculate the maximum number of phone numbers that can be made
    for(int i = 0; i < 10; i++) {
        if(i == 8) {
            numOfPhoneNumbers = min(numOfPhoneNumbers, count[i] / 11);
        } else {
            numOfPhoneNumbers = min(numOfPhoneNumbers, count[i]);
        }
    }
    
    cout << numOfPhoneNumbers << endl;
    
    return 0;
}