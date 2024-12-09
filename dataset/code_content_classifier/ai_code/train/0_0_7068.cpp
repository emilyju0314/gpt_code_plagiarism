#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h;
    cin >> h;
    
    vector<int> sequence(h + 1);
    for (int i = 0; i <= h; i++) {
        cin >> sequence[i];
    }
    
    bool isPerfect = true;
    for (int i = 1; i <= h; i++) {
        if (sequence[i] > 1 && sequence[i-1] > 1) {
            isPerfect = false;
            break;
        }
    }
    
    if (isPerfect) {
        cout << "perfect\n";
    } else {
        cout << "ambiguous\n";
        
        vector<int> tree1, tree2;
        int lastNode = 0;
        for (int i = 0; i <= h; i++) {
            for (int j = 0; j < sequence[i]; j++) {
                tree1.push_back(lastNode);
                tree2.push_back(lastNode);
                lastNode = tree1.size() - 1;
            }
            if (i != 0) {
                tree1[lastNode] = i - 1;
                tree2[lastNode] = (i == 1 ? 0 : i - 1);
            }
        }
        
        for (int i = 0; i < tree1.size(); i++) {
            cout << tree1[i] << " ";
        }
        cout << endl;
        
        for (int i = 0; i < tree2.size(); i++) {
            cout << tree2[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}