#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    string s;
    cin >> s;
    string x_str;
    cin >> x_str;

    long long x = stoll(x_str);

    unordered_map<long long, pair<int, int>> prefix_sum;
    long long curr_sum = 0;
    prefix_sum[0] = make_pair(-1, -1);

    for (int i = 0; i < s.size(); i++) {
        curr_sum = curr_sum * 10 + (s[i] - '0');
        prefix_sum[curr_sum] = make_pair(prefix_sum[curr_sum].first, i);
    }

    curr_sum = 0;
    for (int i = 0; i < s.size(); i++) {
        curr_sum = curr_sum * 10 + (s[i] - '0');
        long long remainder = x - curr_sum;
        if (prefix_sum.find(remainder) != prefix_sum.end()) {
            pair<int, int> p1 = prefix_sum[curr_sum];
            pair<int, int> p2 = prefix_sum[remainder];
            cout << p1.first + 2 << " " << p1.second + 1 << endl;
            cout << p2.first + 2 << " " << p2.second + 1 << endl;
            break;
        }
    }

    return 0;
}