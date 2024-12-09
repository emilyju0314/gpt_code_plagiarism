#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;
    
    int count = 0;
    for(int i = 0; i < input.length(); i++) {
        if(input[i] == 'A' || input[i] == 'C' || input[i] == 'M') {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}