#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, l, v1, v2;
    cin >> n >> l >> v1 >> v2;

    vector<int> chocolates(n);
    for (int i = 0; i < n; i++) {
        cin >> chocolates[i];
    }

    double total_time = (double)(l) / (double)(v1 + v2);
    
    for (int i = 0; i <= n; i++) {
        double sum = 0.0;
        for (int j = 0; j < n; j++) {
            if (j < i) {
                sum += 2.0 * l / (double)(v1 + v2);
            } else {
                sum += 2.0 * (l + chocolates[j]) / (double)(v1 + v2);
            }
        }
        sum += l / (double)(v1 + v2);
        
        double prob = sum / total_time;
        cout << fixed << setprecision(20) << prob << endl;
    }

    return 0;
}