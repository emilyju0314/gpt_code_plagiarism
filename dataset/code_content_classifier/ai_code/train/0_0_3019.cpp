#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string name;
    
    cin >> n >> name;
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        sum += num;
    }
    
    cout << sum << endl;
    
    return 0;
}