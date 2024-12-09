#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    string l, r;
    cin >> l >> r;

    set<string> tails;

    for (int i = stoi(l); i <= stoi(r); i++) {
        string num = to_string(i);
        sort(num.begin(), num.end());
        int j = 0;
        while (num[j] == '0') {
            j++;
        }
        tails.insert(num.substr(j));
    }

    cout << tails.size() << endl;

    return 0;
}