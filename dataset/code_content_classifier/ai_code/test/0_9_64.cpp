#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string s;
    long long x;
    cin >> s >> x;

    unordered_map<long long, int> position;
    int n = s.length();

    long long sum = 0;
    position[sum] = 0;
    for (int i = 0; i < n; i++) {
        sum = sum * 10 + (s[i] - '0');
        position[sum] = i + 1;
    }

    for (int i = 1; i < n; i++) {
        long long a = stoll(s.substr(0, i));
        long long b = x - a;
        if (position.find(b) != position.end()) {
            cout << "1 " << i << endl;
            cout << i + 1 << " " << position[b] << endl;
            break;
        }
    }

    return 0;
}