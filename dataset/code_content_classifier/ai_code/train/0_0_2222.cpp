Here's a sample C++ code to solve the problem:


#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    int n;
    cin >> n;

    int maxVolume = 0;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        
        int volume = 0;
        for (char c : word) {
            if (isupper(c)) {
                volume++;
            }
        }
        
        maxVolume = max(maxVolume, volume);
    }

    cout << maxVolume << endl;
    
    return 0;
}