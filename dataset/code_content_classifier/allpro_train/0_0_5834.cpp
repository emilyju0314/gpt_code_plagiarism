#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m;
    cin >> m;
    
    vector<int> sequence;
    
    for(int i=0; i<m; i++){
        int type;
        cin >> type;
        
        if(type == 1){
            int num;
            cin >> num;
            sequence.push_back(num);
        } else {
            int l, c;
            cin >> l >> c;
            
            for(int j=0; j<c; j++){
                for(int k=0; k<l; k++){
                    sequence.push_back(sequence[k]);
                }
            }
        }
    }
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        cout << sequence[num-1] << " ";
    }
    
    return 0;
}