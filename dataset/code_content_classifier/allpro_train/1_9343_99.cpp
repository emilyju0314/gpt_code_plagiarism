#include <iostream>
#include <string>
using namespace std;

string str = "',.!?abcABCdefDEFghiGHIjklJKLmnoMNOpqrsPQRStuvTUVwxyzWXYZ";

char ch(int key,int n){
    int t = 0;
    
    switch(key){
        case 1:
            return str[n-1+t];
        case 2:
            t = 5;
            return str[n-1+t];
        case 3:
            t = 11;
            return str[n-1+t];
        case 4:
            t = 17;
            return str[n-1+t];
        case 5:
            t = 23;
            return str[n-1+t];
        case 6:
            t = 29;
            return str[n-1+t];
        case 7:
            t = 35;
            return str[n-1+t];
        case 8:
            t = 43;
            return str[n-1+t];
    }
    t = 49;
    return str[n-1+t];
}

int main(){
    string s;
    
    while(cin >> s){
        int len = s.size();
        
        int k = 0;
        if(s[len-1]!='0'){
            s += '0';
            k = 1;
        }
        
        char tmp=s[0]; int cnt = 1;
        string ans = "";
        for(int i = 1 ; i < len+k ; i++){
            if(tmp == s[i]) cnt++;
            else if(tmp != s[i]){
                if(tmp != '0'){
                    ans += ch(tmp-'0',cnt);
                }
                else{
                    if(cnt==2){
                        ans += " ";
                    }
                    else if(cnt==3){
                        ans += "  ";
                    }
                }
                tmp = s[i];
                cnt = 1;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}