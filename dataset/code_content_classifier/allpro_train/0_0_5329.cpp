#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    set<string> suffixes;

    if(s.length() < 5) {
        cout << "0" << endl;
    } else {
        for(int i = 5; i <= min((int)s.length(), 8); i++) {
            suffixes.insert(s.substr(i, 2));
            if(i < (int)s.length() - 1) {
                suffixes.insert(s.substr(i, 3));
            }
        }

        cout << suffixes.size() << endl;
        for(const string& suffix : suffixes) {
            cout << suffix << endl;
        }
    }

    return 0;
}