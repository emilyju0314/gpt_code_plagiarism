#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, a, b, c, d;
    cin >> n >> k;
    cin >> a >> b >> c >> d;

    if (n < 4 || k < n || n == 4) {
        cout << -1 << endl;
    } else {
        vector<int> path1, path2;

        path1.push_back(a);
        path1.push_back(c);
        
        int current = c;
        while (current != d) {
            current = current % n + 1;
            if (current == a || current == b || current == c || current == d) {
                continue;
            }
            path1.push_back(current);
        }

        path1.push_back(d);
        path1.push_back(b);
        
        path2.push_back(c);
        path2.push_back(a);

        current = a;
        while (current != b) {
            current = current % n + 1;
            if (current == a || current == b || current == c || current == d) {
                continue;
            }
            path2.push_back(current);
        }

        path2.push_back(b);
        path2.push_back(d);

        if (path1.size() + path2.size() > k) {
            cout << -1 << endl;
        } else {
            for (int city : path1) {
                cout << city << " ";
            }
            cout << endl;
            for (int city : path2) {
                cout << city << " ";
            }
            cout << endl;
        }
    }

    return 0;
}