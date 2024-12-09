#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> weights(n);
    for(int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    string s;
    cin >> s;
    
    // Initialize left and right pointers
    int left = 0, right = n - 1;
    
    // Iterate through the string S to determine the side of the balance
    for(char c : s) {
        if(c == 'L') {
            cout << weights[left] << " L" << endl;
            left++;
        } else {
            cout << weights[right] << " R" << endl;
            right--;
        }
    }
    
    return 0;
}