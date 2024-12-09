#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        string str;
        cin >> str;

        cout << str << "<><>" << to_string(stoi(str) + 1) << endl;
    }

    return 0;
}