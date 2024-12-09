#include <iostream>
#include <vector>

using namespace std;

int query(const string& s) {
    cout << "? " << s << endl;
    cout.flush();
    int distance;
    cin >> distance;
    return distance;
}

int main() {
    int n;
    cin >> n;

    string query_str;

    // Query all positions in the string
    for(int i = 0; i < n; i++) {
        query_str += '0';
        query_str[i] = '1';
        int distance = query(query_str);

        if(distance == n) {
            // Found the 1 position
            query_str[i] = '0';
            break;
        }

        query_str[i] = '0';
    }

    int one_position = query_str.find('1') + 1;

    // Find the position of 0
    query_str = string(n, '1');
    query(query_str);

    int zero_position = query_str.find('0') + 1;

    cout << "! " << zero_position << " " << one_position << endl;
    cout.flush();

    return 0;
}