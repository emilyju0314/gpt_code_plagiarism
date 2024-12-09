#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> pots(n);
    for(int i = 0; i < n; i++) {
        cin >> pots[i];
    }

    vector<int> untasted(n, 1);
    double totalUntasted = n;

    cin >> q;
    for(int i = 0; i < q; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        
        double subtract = 0;
        for(int j = 0; j < k; j++) {
            if(untasted[u-1] == 1) {
                subtract += 1.0 / pots[u-1];
                untasted[u-1] = 0;
                totalUntasted -= 1;
            }
            pots[u-1]--;
            pots[v-1]++;
        }

        double result = totalUntasted;
        result -= subtract;
        cout << fixed << setprecision(9) << result << endl;
    }

    return 0;
}