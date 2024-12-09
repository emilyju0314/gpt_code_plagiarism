#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, count = 0;
    cin >> N;
    
    string str = to_string(N);
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '2') {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}