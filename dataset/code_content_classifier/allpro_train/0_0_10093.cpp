#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int calculateError(string addressEntered, string potentialAddress) {
    int error = 0;
    for(int i = 0; i < potentialAddress.size(); i++) {
        char ci = potentialAddress[i];
        int j = addressEntered.find(ci);
        if(j != string::npos) {
            error += abs(i - j);
        } else {
            error += potentialAddress.size();
        }
    }
    return error;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    string addressEntered;
    cin >> addressEntered;
    
    for(int i = 0; i < n; i++) {
        string potentialAddress;
        cin >> potentialAddress;
        
        int error = calculateError(addressEntered, potentialAddress);
        cout << error << endl;
    }
    
    return 0;
}