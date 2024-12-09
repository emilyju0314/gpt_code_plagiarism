#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int count = 0;
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        if (name == "E869120") {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}