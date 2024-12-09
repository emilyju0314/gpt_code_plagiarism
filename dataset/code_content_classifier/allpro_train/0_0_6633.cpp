#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;

    for(int i=0; i<q; i++){
        int ni;
        cin >> ni;

        if(ni == 1){
            cout << "0" << endl;
        } else if(ni == 2){
            cout << "1" << endl;
        } else {
            cout << ni << endl;
        }
    }

    return 0;
}