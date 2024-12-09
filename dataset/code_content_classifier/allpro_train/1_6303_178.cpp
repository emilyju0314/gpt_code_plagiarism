#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<string> card(3);
    for(int i=0; i<3; i++)
        cin>>card[i];
    int n=0;
    while(1){
        if(card[n].empty()){
            printf("%c",'A'+n);
            return 0;
        }
        int t=card[n][0]-'a';
        card[n].erase(begin(card[n]));
        n=t;
    }
}