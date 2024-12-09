#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int,int> space;
    int a_size;

    while(cin >> a_size, a_size != 0){
        space.clear();
        for(int i=1; i<=a_size; i++){
            int n;
            cin >> n;
            space[n]++;
        }
        map<int, int>::iterator it = space.begin();
        bool flug = false;
        while(it != space.end()){
            if((*it).second > a_size/2){
                cout << (*it).first << endl;
                flug = true;
                break;
            }
            it++;
        }
        if(flug == false){
            cout << "NO COLOR" << endl;
        }
    }
    return 0;
}