#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string fileName;

    cin >> n;
    cin >> fileName;

    int count = 0;
    for(int i = 0; i < n - 2; i++) {
        if(fileName.substr(i, 3) == "xxx") {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}