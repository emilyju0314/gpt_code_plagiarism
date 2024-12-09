#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> differences(n, 0);

    for (int i = 0; i < q; i++) {
        int type, x, y, z;
        cin >> type >> x >> y;
        
        if (type == 0) {
            cin >> z;
            differences[y] = differences[x] + z;
        } else {
            if (differences[x] == 0 || differences[y] == 0) {
                cout << "?" << endl;
            } else {
                cout << differences[y] - differences[x] << endl;
            }
        }
    }

    return 0;
}