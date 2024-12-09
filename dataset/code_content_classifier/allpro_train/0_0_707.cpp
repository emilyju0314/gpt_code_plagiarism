#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n, 0);
    vector<bool> queried(n, false);

    for (int i = 1; i < n; ++i) {
        cout << "? " << 1 << " " << i + 1 << endl;
        cout.flush();

        int result;
        cin >> result;

        p[i] = result;
    }

    cout << "? " << 2 << " " << 3 << endl;
    cout.flush();

    int result;
    cin >> result;

    p[0] = (p[1] | p[2]) ^ result;
    
    cout << "! ";
    for (int i = 0; i < n; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;
    cout.flush();

    return 0;
}