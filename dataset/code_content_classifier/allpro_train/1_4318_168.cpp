#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main (){
    map< double , int > a[3];
    map< double , int > b;
    for(int i=0;i<3;i++){
        for(int j=0;j<8;j++){
           int x;
           double y;
           cin>>x>>y;
           a[i][y] = x;
        }
        map< double , int >::iterator it = a[i].begin();
        cout<<(*it).second<<" "<<(*it).first<<endl;
        it++;
        cout<<(*it).second<<" "<<(*it).first<<endl;

        int n=6;
        while(n--){
            it++;
            b[(*it).first] = (*it).second;
        }


    }
    map< double , int >::iterator it = b.begin();
        cout<<(*it).second<<" "<<(*it).first<<endl;
        it++;
        cout<<(*it).second<<" "<<(*it).first<<endl;

    for(int i=0;i<3;i++)a[i].clear();
    b.clear();
    return 0;
}