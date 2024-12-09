#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int x = 0;
    string statement;
    
    for (int i = 0; i < n; i++) {
        cin >> statement;
        if (statement == "++X" || statement == "X++") {
            x++;
        } else if (statement == "--X" || statement == "X--") {
            x--;
        }
    }
    
    cout << x << endl;
    
    return 0;
}