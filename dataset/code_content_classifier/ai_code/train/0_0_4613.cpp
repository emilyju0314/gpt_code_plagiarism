#include <iostream>
#include <vector>

using namespace std;

void generateNestedList(int n) {
    vector<int> list;
    for (int i = 1; i <= n; i++) {
        list.push_back(i);
        for (int j = list.size() - 2; j >= 0; j--) {
            if (list[j] + 1 == list[j + 1]) {
                break;
            }
            if (list[j] != 1) {
                list[j] += 1;
                break;
            } else {
                list[j] = 1;
            }
        }
        for (int j = 0; j < list.size(); j++) {
            cout << list[j];
            if (j != list.size() - 1) {
                cout << ".";
            }
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        generateNestedList(n);
    }
    
    return 0;
}