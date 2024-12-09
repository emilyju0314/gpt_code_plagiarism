#include <iostream>
#include <string>

using namespace std;

string calculateWinner(string num) {
    int len = num.length();
    
    if (len % 2 == 0) {
        return "Audrey wins.";
    } else {
        return "Fabre wins.";
    }
}

int main() {
    int datasets;
    cin >> datasets;
    
    for (int i = 0; i < datasets; i++) {
        string num;
        cin >> num;
        
        cout << calculateWinner(num) << endl;
    }
    
    return 0;
}