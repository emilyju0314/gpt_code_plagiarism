#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == 1 && b[j] == 1) {
                int area = 1;
                for (int x = i + 1; x < n; x++) {
                    for (int y = j + 1; y < m; y++) {
                        if (a[x] == 1 && b[y] == 1) {
                            area++;
                            if (area == k) {
                                count++;
                            }
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}