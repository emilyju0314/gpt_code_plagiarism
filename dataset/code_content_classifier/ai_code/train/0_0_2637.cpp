#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> folds;
    
    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;
        
        if(type == 1) {
            int pi;
            cin >> pi;
            folds.push_back(pi);
        } else {
            int li, ri;
            cin >> li >> ri;
            int totalWidth = n;
            
            for(int fold : folds) {
                if(fold < ri && fold >= li) {
                    totalWidth -= min(ri - fold, fold - li);
                } else if(fold >= ri) {
                    totalWidth -= ri - li;
                } else if(fold < li) {
                    totalWidth -= ri - li;
                }
            }
            
            cout << totalWidth << endl;
        }
    }
    
    return 0;
}