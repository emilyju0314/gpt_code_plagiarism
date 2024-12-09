#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> powers(N);
    for (int i = 0; i < N; i++) {
        cin >> powers[i];
    }

    for (int i = 0; i < M; i++) {
        int type, a, b;
        cin >> type >> a;
        
        if (type == 1) {
            int jumps = 0;
            int last_hole = a;
            while (true) {
                if (last_hole + powers[last_hole - 1] > N) {
                    cout << last_hole << " " << jumps << endl;
                    break;
                } else {
                    last_hole += powers[last_hole - 1];
                    jumps++;
                }
            }
        } else {
            cin >> b;
            powers[a - 1] = b;
        }
    }

    return 0;
}