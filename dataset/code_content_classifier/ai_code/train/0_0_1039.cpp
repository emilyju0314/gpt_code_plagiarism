#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double maxWaterHeight(int N, int M, vector<vector<int>>& vases) {
    double low = 0, high = 10000;
    for (int i = 0; i < 100; i++) {
        double mid = (low + high) / 2;
        double sum = 0;
        for (int j = 0; j < N; j++) {
            double maxHeight = 0;
            for (int k = 1; k < vases[j].size(); k += 2) {
                double baseArea = vases[j][k - 1];
                double height = vases[j][k];
                double radius = sqrt(baseArea / 3.14159265358979);
                double waterHeight = min(height, mid / (radius * radius * 3.14159265358979));
                maxHeight = max(maxHeight, waterHeight);
            }
            sum += maxHeight;
        }
        if (sum >= M) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return low;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> vases(N);
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        for (int j = 0; j < 2 * K; j++) {
            int val;
            cin >> val;
            vases[i].push_back(val);
        }
    }
    
    double result = maxWaterHeight(N, M, vases);
    cout << result << endl;
    
    return 0;
}